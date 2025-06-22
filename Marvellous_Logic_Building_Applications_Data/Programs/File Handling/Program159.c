//Write a program in c which is use to create file as per user given file name
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>
#include<fcntl.h>

int main()
{
	int fd=0;
	char Fname[30];
	
	printf("Enter file name: ");
	scanf("%s",Fname);
	
	fd=creat(Fname,O_RDWR);
	
	if(fd==-1)
	{
		printf("Unable to open the file.\n");
	}
	else
	{
		printf("File succesfully open with FD: %d\n",fd);
	}
	return 0;
}