# environment configuration template for occ_build_wasm.sh (to be renamed as wasm_custom_env.sh)
export aFreeType="$aSrcRoot/../freetype"
export EMSDK_ROOT="${EMSDK}"

# Uncomment to customize building steps
#export aBuildRoot=work
#export toCMake=1
#export toClean=0
#export toMake=1
#export toInstall=1

#export BUILD_ModelingData=ON
#export BUILD_ModelingAlgorithms=ON
#export BUILD_Visualization=ON
#export BUILD_ApplicationFramework=ON
#export BUILD_DataExchange=ON
