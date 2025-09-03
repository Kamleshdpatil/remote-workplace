#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

bool isStringPalimdromeRecursive(char *str, size_t n, int i)
{
    if(i > n/2)
    {
        return true;
    }

    if(str[i] != str[n-i-1])
    {
        return false;
    }
    
    return isStringPalimdromeRecursive(str, n, i + 1);
}


int main()
{
    char str[256];
    scanf("%[^\n]s", str);
    //char *str = {"abbba"};
    int n = strlen(str);
    printf("Size is: %d\n\n", n);
    bool bret = isStringPalimdromeRecursive(str, n, 0);
    if(bret == true)
    {
        printf("%s Is palimdrome!!\n\n", str);
    }else{
        printf("%s Is not palimdrome!!\n\n", str);
    }

    return 0;
}
