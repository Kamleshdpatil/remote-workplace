//Write a program in c which is use to create file and write string in that file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>
#include<fcntl.h>

int main()
{
	int fd=0, iRet=0;
	char Fname[30];
	char Data[7];
	
	printf("Enter file name: ");
	scanf("%s",Fname);
	
	fd=open(Fname,O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open file.\n");
		return -1;  //return to OS
	}
	else
	{
		printf("File succesfully open with FD: %d\n",fd);
	}
	
	iRet=read(fd,Data,7);
	
	printf("Readed data\n");
	write(1,Data,iRet);
	close(fd);
	
	return 0;
}