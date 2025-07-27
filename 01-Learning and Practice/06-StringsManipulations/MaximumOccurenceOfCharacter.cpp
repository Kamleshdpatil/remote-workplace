#include <stdio.h>
#include <string.h>
 
#define ASCII_SIZE 256
char getMaxOccurringChar(char* str)
{
    int count[ASCII_SIZE] = {0};

    int iSize = strlen(str);
    int max = 0;
    char maxChar;

    for(int i = 0; i < iSize; i++)
    {
        count[(int)str[i]]++;
        printf(" %c is %d times|\n", str[i], count[(int)str[i]]);
        if(count[(int)str[i]] > max)
        {
            max = count[(int)str[i]];
            maxChar = str[i];
        }
    }
    return(maxChar);
}

// Driver program to test the above function
int main()
{
    char str[] = "Kamlesh will be a reat developerE";
    //char str[256];
    //scanf("%[^\n]s", str);
    printf("\n\nMax occurring character is: '%c'",
           getMaxOccurringChar(str));
}