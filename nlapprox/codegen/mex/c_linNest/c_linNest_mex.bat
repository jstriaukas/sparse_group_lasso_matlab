@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=c_linNest_mex
set MEX_NAME=c_linNest_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for c_linNest > c_linNest_mex.mki
echo COMPILER=%COMPILER%>> c_linNest_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> c_linNest_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> c_linNest_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> c_linNest_mex.mki
echo LINKER=%LINKER%>> c_linNest_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> c_linNest_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> c_linNest_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> c_linNest_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> c_linNest_mex.mki
echo BORLAND=%BORLAND%>> c_linNest_mex.mki
echo OMPFLAGS= >> c_linNest_mex.mki
echo OMPLINKFLAGS= >> c_linNest_mex.mki
echo EMC_COMPILER=mingw64>> c_linNest_mex.mki
echo EMC_CONFIG=optim>> c_linNest_mex.mki
"C:\Program Files\MATLAB\R2017a\bin\win64\gmake" -B -f c_linNest_mex.mk
