cls
del *.exe
del *.obj
cl.exe /c /EHsc SocketServer.cpp
link.exe SocketServer.obj wsock32.lib
cls
SocketServer.exe
