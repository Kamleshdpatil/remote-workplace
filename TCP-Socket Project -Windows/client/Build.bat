cls
del *.exe
del *.obj
cl.exe /c /EHsc ../logger/logger.cpp SocketClient.cpp
link.exe SocketClient.obj logger.obj wsock32.lib
//cls
SocketClient.exe
