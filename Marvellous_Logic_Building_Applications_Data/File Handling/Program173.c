//Write a program in c which is use to create file and write string in that file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<io.h>
#include<fcntl.h>

int main()
{
	int fd=0;
	char Arr[10];
	
	fd=open("LB17.txt",O_RDWR);
	if(fd==-1)
	{
		printf("Unable to open file\n");
	}
	
	////////////
	//0  From starting position 
	//1 From current position
	//2 From end of the file
	
	lseek(fd,-5,2);
	
	read(fd,Arr,5);
	
	
	write(1,Arr,5);
	
	close(fd);
	
	return 0;
}