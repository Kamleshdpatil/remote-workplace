clear

#Remove old binaries/object files
rm -f *.o
rm -f Server
rm -f Client

echo "Compiling Server..."

g++ -c ../logger/logger.cpp SocketServer.cpp

if [ $? -ne 0]
then
    echo "Server Compilation Failed !!"
    exit 1
fi

echo "Linking Server..."

g++ SocketServer.o logger.o -o Server

if [ $? -ne 0]
then
    echo "Server Linking Failed !!"
    exit 1
fi

clear

echo "Running Server .."
./Server

