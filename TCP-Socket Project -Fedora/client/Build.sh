clear

#Remove old binaries/object files
rm -f *.o
rm -f Server
rm -f Client

echo "Compiling Client..."

g++ -c ../logger/logger.cpp SocketClient.cpp

if [ $? -ne 0]
then
    echo "Client Compilation Failed !!"
    exit 1
fi

echo "Linking Client..."

g++ SocketClient.o logger.o -o Client

if [ $? -ne 0]
then
    echo "Client Linking Failed !!"
    exit 1
fi

clear

echo "Running Client .."
./Client

