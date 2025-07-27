#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int findFize(char s[])
{
    int size = 0;
    
    for(size = 0; s[size] != '\0'; size++);
    
    return size;
}

void printFrequencyOfdigit(char s[], int n)
{
    int eachDigitCount = 0;
    char ch = '\0';
    for(int i = 0; i<n; i++)
    {
        ch = s[i];
        for(int j = 0; j<n; j++)
        {
            if(ch == s[j])
            {
                eachDigitCount++;
            }
        }
        if((ch >= 65 || ch<=90) || (ch>=97 || ch<=122))
        {
            printf("0 ");
        }
        else
        {
            printf("%d ", eachDigitCount);
        }
        eachDigitCount = 0;
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[]= "a11472o5t6";
    //scanf("%[^\n]s", s);
    
    int size = findFize(s);
    printFrequencyOfdigit(s, size);
        
    return 0;
}
