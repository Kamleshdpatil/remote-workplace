#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd=0;
    
    fd=open("go",O_RDWR);  //ABCDEFGHIJKLMNOPQRSTUVWXYZ
    if(fd==-1)
    {
        printf("Unable to oepn file\n");
        return -1;
    }
    lseek(fd,10,2); 

    write(fd,"*",1); //hole in data bcoz lseek 10 
    
    
    close(fd);
    return 0;
}