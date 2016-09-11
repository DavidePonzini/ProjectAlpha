@echo off

rem FOLDERS
rmdir /s /q .vs Binaries Intermediate Saved

rem FILES
del /s /q ProjectAlpha.sln ProjectAlpha.VC.db

pause