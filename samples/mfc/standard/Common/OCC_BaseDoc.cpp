// OCC_BaseDoc.cpp: implementation of the OCC_BaseDoc class.
//
//////////////////////////////////////////////////////////////////////

#include <stdafx.h>
#include "OCC_BaseDoc.h"

const CString OCC_BaseDoc::SupportedImageFormats() const
{
  return ("BMP Files (*.BMP)|*.bmp|GIF Files (*.GIF)|*.gif|TIFF Files (*.TIFF)|*.tiff|"
          "PPM Files (*.PPM)|*.ppm|JPEG Files(*.JPEG)|*.jpeg|PNG Files (*.PNG)|*.png|"
          "EXR Files (*.EXR)|*.exr|TGA Files (*.TGA)|*.tga|PS Files (*.PS)|*.ps|"
          "EPS Files (*.EPS)|*.eps|TEX Files (*.TEX)|*.tex|PDF Files (*.PDF)|*.pdf"
          "|SVG Files (*.SVG)|*.svg|PGF Files (*.PGF)|*.pgf");
}

void OCC_BaseDoc::ExportView (const Handle(V3d_View)& theView) const
{
   CFileDialog anExportDlg (FALSE,_T("*.BMP"),NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                            SupportedImageFormats() + "||", NULL );

  if (anExportDlg.DoModal() == IDOK)
  {
    // Set waiting cursor
    SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT));

    CString aFileName = anExportDlg.GetPathName();
    CString aFileExt = anExportDlg.GetFileExt();

    // For vector formats use V3d_View::Export() method
    if (!(aFileExt.CompareNoCase ("ps")) || !(aFileExt.CompareNoCase ("pdf"))
        || !(aFileExt.CompareNoCase ("eps")) || !(aFileExt.CompareNoCase ("tex"))
        || !(aFileExt.CompareNoCase ("svg")) || !(aFileExt.CompareNoCase ("pgf")))
    {
      Graphic3d_ExportFormat anExportFormat;

      if (!(aFileExt.CompareNoCase ("ps"))) anExportFormat = Graphic3d_EF_PostScript;
      else if (!(aFileExt.CompareNoCase ("eps"))) anExportFormat = Graphic3d_EF_EnhPostScript;
      else if (!(aFileExt.CompareNoCase ("pdf"))) anExportFormat = Graphic3d_EF_PDF;
      else if (!(aFileExt.CompareNoCase ("tex"))) anExportFormat = Graphic3d_EF_TEX;
      else if (!(aFileExt.CompareNoCase ("svg"))) anExportFormat = Graphic3d_EF_SVG;
      else anExportFormat = Graphic3d_EF_PGF;

      theView->View()->Export (aFileName, anExportFormat);
    }
    else
    {
      // For pixel formats use V3d_View:Dump() method
      theView->Dump (aFileName);
    }

    // Restore cursor
    SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
  }
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OCC_BaseDoc::OCC_BaseDoc()
{

}

OCC_BaseDoc::~OCC_BaseDoc()
{

}
