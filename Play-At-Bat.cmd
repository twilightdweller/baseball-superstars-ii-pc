@echo off
if not exist "%~dp0build\BS2-Pitch-Motion.exe" (
    echo Build the game first with python verify_windows.py.
    pause
    exit /b 1
)
start "" "%~dp0build\BS2-Pitch-Motion.exe" --at-bat
