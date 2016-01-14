mkdir mingw-build
g++ -std=c++11 -finput-charset=CP1251 config.h defines.h utils.h Game.cpp CyberCode.cpp -o mingw-build\CyberCode.exe