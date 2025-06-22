//Write a program in c which is use to open file count 'a'
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>
#include<fcntl.h>

int main()
{
	int fd=0, i=0, iRet=0, iSum;
	char fname[20];
	char Buffer[10];
	
	printf("Enter file name: ");
	scanf("%s",fname);
	
	fd=open(fname,O_RDWR);
	
	if(fd==-1)
	{
		printf("Unable to open file");
		return -1;
	}
	
	while((iRet=read(fd,Buffer,10)) !=0)
	{
		iSum=iRet+iSum;
	}
	
	printf("Count of All letters are: %d",iSum);
	
	close(fd);
	return 0;
}