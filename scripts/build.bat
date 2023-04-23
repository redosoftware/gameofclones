@echo off

IF NOT EXIST build mkdir build
pushd build

rem To understand /EHsc, see https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-1-c4530?view=msvc-170 

cl -Zi /W4 /WX /EHsc ..\%1

popd