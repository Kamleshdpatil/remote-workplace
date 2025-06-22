//Write a program in c which is use to create file and write string in that file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>
#include<fcntl.h>

int main()
{
	int fdSrc=0, fdDest=0, iRet=0;
	char Fname1[30];
	char Fname2[30];
	char Buffer[1024];
	
	printf("Enter source file name: ");
	scanf("%s",Fname1);
	
	fdSrc=open(Fname1,O_RDONLY);
	
	if(fdSrc == -1)
	{
		printf("Unable to open file.\n");
		return -1;  //return to OS
	}
	else
	{
		printf("File succesfully open with FD: %d\n",fdSrc);
	}
	printf("Enter destination file name: ");
	scanf("%s",Fname2);
	fdDest=creat(Fname2,0777);
	
	printf("Data From file is: \n");
	while((iRet=read(fdSrc,Buffer, sizeof(Buffer))) != 0)
	{
		write(fdDest,Buffer,iRet);
		//printf("%s",Buffer);
	}
	
	close(fdSrc);
	close(fdDest);
	
	return 0;
}