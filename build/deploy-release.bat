@echo off

REM Ask for the full path to the .exe file
echo Enter the full path to your .exe file (e.g., C:\Projects\ProCalc\build\Release\ProCalc.exe):
set /p EXE_PATH=

REM Line break after input
echo.

REM Remove any surrounding quotes from EXE_PATH
set EXE_PATH=%EXE_PATH:"=%

REM Extract the directory path from the .exe path
for %%F in ("%EXE_PATH%") do set APP_PATH=%%~dpF

REM Ask for the Qt installation path
echo Enter the full path to your Qt installation's mingw_64 folder (e.g., C:\Qt\6.7.2\mingw_64):
set /p QT_PATH=

REM Line break after input
echo.

REM Remove any surrounding quotes from QT_PATH
set QT_PATH=%QT_PATH:"=%

REM Print the variables to debug
echo EXE_PATH is "%EXE_PATH%"
echo APP_PATH is "%APP_PATH%"
echo QT_PATH is "%QT_PATH%"

REM Set MinGW path based on the user input
set MINGW_PATH=%QT_PATH%\bin

REM Verify the paths
if not exist "%EXE_PATH%" (
    echo "%EXE_PATH%" does not exist.
    pause
    exit /b
)

if not exist "%APP_PATH%" (
    echo "%APP_PATH%" does not exist.
    pause
    exit /b
)

if not exist "%QT_PATH%" (
    echo "%QT_PATH%" does not exist.
    pause
    exit /b
)

REM Copy necessary Qt DLLs using windeployqt
%QT_PATH%\bin\windeployqt.exe "%EXE_PATH%" --release

REM Manually copy MinGW runtime DLLs
echo Copying MinGW DLLs...
copy "%MINGW_PATH%\libgcc_s_seh-1.dll" "%APP_PATH%"
copy "%MINGW_PATH%\libstdc++-6.dll" "%APP_PATH%"
copy "%MINGW_PATH%\libwinpthread-1.dll" "%APP_PATH%"

echo All necessary DLLs have been copied.
pause
