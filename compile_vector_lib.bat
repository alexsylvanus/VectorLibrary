@echo off

rem Compile the library source
cl /c /Iinc src\*.c /Foobjects\ /DLIBRARY_EXPORTS

rem Link the objects into library
link objects\*.obj /DLL /OUT:libavector.dll

rem Compile main
cl /c /Iinc main.c

rem Link main.obj with library
cl /Iinc main.obj libavector.lib