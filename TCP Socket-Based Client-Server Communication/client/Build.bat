cls
del *.exe
del *.obj
cl.exe /c /EHsc SocketClient.cpp
link.exe SocketClient.obj wsock32.lib
cls
SocketClient.exe
