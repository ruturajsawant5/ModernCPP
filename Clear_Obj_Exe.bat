@echo off
echo This script will recursively traverse all directories from the current location and delete *.obj and *.exe files.
echo.
pause

echo Starting the cleanup process...

FOR /R %%f IN (*.obj *.exe) DO (
    if exist "%%f" (
        del /f "%%f"
        echo Deleted: "%%f"
    )
)

echo.
echo Cleanup process completed.
pause