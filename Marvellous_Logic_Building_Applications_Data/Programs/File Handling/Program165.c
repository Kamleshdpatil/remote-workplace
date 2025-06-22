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
	char Buffer[10];
	
	printf("Enter file name: ");
	scanf("%s",Fname);
	
	fd=open(Fname,O_RDONLY);
	
	if(fd == -1)
	{
		printf("Unable to open file.\n");
		return -1;  //return to OS
	}
	else
	{
		printf("File succesfully open with FD: %d\n",fd);
	}
	printf("Data From file is: \n");
	while((iRet=read(fd,Buffer, sizeof(Buffer))) != 0)
	{
		write(1,Buffer,iRet);
		//printf("%s",Buffer);
	}
	
	close(fd);
	
	return 0;
}