#!/bin/bash

aScriptPath=${BASH_SOURCE%/*}; if [ -d "${aScriptPath}" ]; then cd "$aScriptPath"; fi; aScriptPath="$PWD";

if [ "${CASROOT}" == "" ]; then
  export CASROOT="${aScriptPath}"
fi

# Read script arguments
shopt -s nocasematch
export CASDEB="";
if [[ "$1" == "debug" ]]; then export CASDEB="d"; fi
if [[ "$1" == "d" ]]; then export CASDEB="d"; fi
if [[ "$1" == "relwithdeb" ]]; then export CASDEB="i"; fi
if [[ "$1" == "i" ]]; then export CASDEB="i"; fi
shopt -u nocasematch

export COMPILER="clang"

# ----- Set path to 3rd party and OCCT libraries -----
anArch=`uname -m`
if [ "$anArch" != "x86_64" ] && [ "$anArch" != "ia64" ]; then
  export ARCH="32";
else
  export ARCH="64";
fi

aSystem=`uname -s`
if [ "$aSystem" == "Darwin" ]; then
  export WOKSTATION="mac";
  export ARCH="64";
else
  export WOKSTATION="lin";
fi

# ----- Set local settings -----
if [ -e "${aScriptPath}/custom.sh" ]; then 
  source "${aScriptPath}/custom.sh" "${COMPILER}" "${ARCH}"
fi

THRDPARTY_PATH=""
if [ "$TCL_DIR" != "" ]; then
  THRDPARTY_PATH="${TCL_DIR}:${THRDPARTY_PATH}"
fi

if [ "$TK_DIR" != "" ]; then
  THRDPARTY_PATH="${TK_DIR}:${THRDPARTY_PATH}"
fi

if [ "$FREETYPE_DIR" != "" ]; then
  THRDPARTY_PATH="${FREETYPE_DIR}:${THRDPARTY_PATH}"
fi

if [ "$FREEIMAGE_DIR" != "" ]; then
  THRDPARTY_PATH="${FREEIMAGE_DIR}:${THRDPARTY_PATH}"
fi

if [ "$GL2PS_DIR" != "" ]; then
  THRDPARTY_PATH="${GL2PS_DIR}:${THRDPARTY_PATH}"
fi

if [ "$TBB_DIR" != "" ]; then
  THRDPARTY_PATH="${TBB_DIR}:${THRDPARTY_PATH}"
fi

if [ "$VTK_DIR" != "" ]; then
  THRDPARTY_PATH="${VTK_DIR}:${THRDPARTY_PATH}"
fi

if [ "$TK_DIR" != "$TCL_DIR" ]; then
  if [ "$TK_DIR" != "" ]; then
    export TK_LIBRARY="${TK_DIR}/../lib/tk"
  fi
  if [ "$TCL_DIR" != "" ]; then
    export TCL_LIBRARY="${TCL_DIR}/../lib/tcl"
  fi
fi

if [ "$LD_LIBRARY_PATH" != "" ]; then
  export LD_LIBRARY_PATH="${THRDPARTY_PATH}:${LD_LIBRARY_PATH}"
else
  export LD_LIBRARY_PATH="${THRDPARTY_PATH}"
fi

if [ "$WOKSTATION" == "mac" ]; then
  if [ "$DYLD_LIBRARY_PATH" != "" ]; then
    export DYLD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${DYLD_LIBRARY_PATH}"
  else
    export DYLD_LIBRARY_PATH="${LD_LIBRARY_PATH}"
  fi
fi

# ----- Set envoronment variables used by OCCT -----
export CSF_LANGUAGE=us
export MMGT_CLEAR=1
export CSF_EXCEPTION_PROMPT=1
export CSF_SHMessage="${OCCT_RESOURCE_PATH}/SHMessage"
export CSF_MDTVTexturesDirectory="${OCCT_RESOURCE_PATH}/Textures"
export CSF_ShadersDirectory="${OCCT_RESOURCE_PATH}/Shaders"
export CSF_XSMessage="${OCCT_RESOURCE_PATH}/XSMessage"
export CSF_TObjMessage="${OCCT_RESOURCE_PATH}/TObj"
export CSF_StandardDefaults="${OCCT_RESOURCE_PATH}/StdResource"
export CSF_PluginDefaults="${OCCT_RESOURCE_PATH}/StdResource"
export CSF_XCAFDefaults="${OCCT_RESOURCE_PATH}/StdResource"
export CSF_TObjDefaults="${OCCT_RESOURCE_PATH}/StdResource"
export CSF_StandardLiteDefaults="${OCCT_RESOURCE_PATH}/StdResource"
export CSF_UnitsLexicon="${OCCT_RESOURCE_PATH}/UnitsAPI/Lexi_Expr.dat"
export CSF_UnitsDefinition="${OCCT_RESOURCE_PATH}/UnitsAPI/Units.dat"
export CSF_IGESDefaults="${OCCT_RESOURCE_PATH}/XSTEPResource"
export CSF_STEPDefaults="${OCCT_RESOURCE_PATH}/XSTEPResource"
export CSF_XmlOcafResource="${OCCT_RESOURCE_PATH}/XmlOcafResource"
export CSF_MIGRATION_TYPES="${OCCT_RESOURCE_PATH}/StdResource/MigrationSheet.txt"

# Draw Harness special stuff
if [ -e "${OCCT_RESOURCE_PATH}/DrawResources" ]; then
  export DRAWHOME="${OCCT_RESOURCE_PATH}/DrawResources"
  export CSF_DrawPluginDefaults="${OCCT_RESOURCE_PATH}/DrawResources"

  if [ -e "${OCCT_RESOURCE_PATH}/DrawResources/DrawDefault" ]; then
    export DRAWDEFAULT="${OCCT_RESOURCE_PATH}/DrawResources/DrawDefault"
  fi
fi

if [ -e "${OCCT_RESOURCE_PATH}/DrawResourcesProducts" ]; then
  export CSF_DrawPluginProductsDefaults="${OCCT_RESOURCE_PATH}/DrawResourcesProducts"
fi

