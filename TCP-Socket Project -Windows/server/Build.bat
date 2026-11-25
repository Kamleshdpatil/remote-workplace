cls
del *.exe
del *.obj
cl.exe /c /EHsc ../logger/logger.cpp SocketServer.cpp
link.exe SocketServer.obj logger.obj wsock32.lib
cls
SocketServer.exe
