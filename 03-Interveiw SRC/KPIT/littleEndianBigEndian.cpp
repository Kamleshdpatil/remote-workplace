#include <stdio.h>

/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

/*Main function to call above function for 0x01234567*/
int main()
{
int i = 0x01234567;
show_mem_rep((char *)&i, sizeof(i));
getchar();
return 0;
}

// 67 45 23 01 - Little endian
// 01 23 45 67 - Big endian
