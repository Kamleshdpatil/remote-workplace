//Write a program in c which is use to create file as per user given file name
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>

int main()
{
	int fd=0;
	char Fname[30];
	
	printf("Enter file name: ");
	scanf("%s",Fname);
	fd=creat(Fname,0777); // 0 for octal, 7 for owner, 7 for group, 7 for ther
							//read 4, write& execute 3, write 2, execute 1 
	if(fd==-1)
	{
		printf("Unable to create the file.\n");
	}
	else
	{
		printf("File succesfully created.\n");
	}
	return 0;
}