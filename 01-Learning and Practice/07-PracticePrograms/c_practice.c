//practice
// C program to demonstrate
// example of toupper() function.
#include <ctype.h>
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool bFlag = false;

char MytoggleCase(char ch)
{
    if((ch == ' ' || ch == '\0') || ch == 27)
    {
        bFlag = true;
    }
    else if(ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;
    }
    else if(ch >= 'a' && ch <= 'z')
    {
        ch = ch - 32;
    }
    return ch;
}

int main()
{
	char ch = '\0';

    while (bFlag != true)
    {
        ch = getch();
        //scanf("%c", &ch);
        printf("\n%c in case is represented as %c\n",
		ch, MytoggleCase(ch));
        continue;
    }
    
	return 0;
}
