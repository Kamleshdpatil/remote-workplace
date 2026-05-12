#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

char name[] = "file";

int main()
{
    int fd;
    fd = creat(name, 0666);
    if(fd == -1){
        printf("creat failed\n");
    }else{
        printf("created\n");
    }
    close(fd);
    return 0;
}