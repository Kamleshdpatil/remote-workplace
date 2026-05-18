#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

char buffer[2048];
int version = 1;

void copy(int old, int new)
{
	int count;
	while((count = read(old, buffer, sizeof(buffer))) > 0)
	{
		write(new, buffer, count);
	}
}

int main(int argc, char* argv[])
{
	int fdold, fdnew;
	
	if(argc != 3)
	{
		printf("Need 2 arguments for copy program\n");
		return(1);
	}
	
	fdold = open(argv[1], O_RDONLY);
	if(fdold == -1)
	{
		printf("Cannont open file %s\n", argv[1]);
		return(1);
	}
	
	fdnew = creat(argv[2], 0666);
	if(fdnew == -1)
	{
		printf("Cannot create a file %s\n", argv[2]);
		return(1);
	}
	
	copy(fdold, fdnew);
	exit(0);
	
}
