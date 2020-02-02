:: This script creates a release (setup) package using a prebuilt project.
@echo off
setlocal

call "%VCINSTALLDIR%\Auxiliary\Build\vcvarsall.bat" x86
msbuild sciviewer.sln /t:Build /p:Configuration=Release;Platform=Win32;UseEnv=true

call "%VCINSTALLDIR%\Auxiliary\Build\vcvarsall.bat" x64
msbuild sciviewer.sln /t:Build /p:Configuration=Release;Platform=x64;UseEnv=true

del /Q sciviewer.zip
copy /y README.md plugin\

powershell.exe -nologo -noprofile -command "& { Add-Type -A 'System.IO.Compression.FileSystem'; [IO.Compression.ZipFile]::CreateFromDirectory('plugin', 'sciviewer.zip'); }"
echo Resulting file sciviewer.zip created!