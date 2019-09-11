set COCOS2DX_HOME=%CD%\..\cocos2d-x-3.17.2
set APP_ROOT=%CD%
set BUILD_PATH=%APP_ROOT%\_build
set SRC_PATH=%APP_ROOT%\Game

rmdir %BUILD_PATH% /q /s
mkdir %BUILD_PATH%
cd %BUILD_PATH%
cmake -G "Visual Studio 15 2017" -DUSE_COCOS_PREBUILT=TRUE %SRC_PATH% -Tv141