//Write a program in c which is use to open file count 'a'
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>
#include<fcntl.h>

int main()
{
	int fd=0, i=0, iCnt=0, iRet=0;
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
		for(i=0; i<iRet; i++)
		{
			if((Buffer[i]>='A') && (Buffer[i]<='Z'))
			{
				iCnt++;
			}
		}
	}
	
	printf("Count of Capital letters are: %d",iCnt);
	
	close(fd);
	return 0;
}