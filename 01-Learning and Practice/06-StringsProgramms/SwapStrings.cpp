#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

void swap(char *str1, char *str2)
{
    char *temp = str1;
    str1 = str2;
    str2 = temp;
}

void swap1(char *str1, char *str2)
{
    int n = strlen(str2)+1;
    int i = 0;
    char *temp = (char*)malloc(sizeof(char) * n);
    while (*str2 != '\0')
    {
        printf("%c ",*str2);
        temp[i] = *str2;
        i++;
        str2++;
    }
    temp[n-1] = '\0';
    cout<<"\nAfter Swap\n";
    printf("temp: %s", temp);
}

int main()
{
    char *str1 = "geeks";
    char *str2 = "forgeeks";
    // cout<<"Before Swap\n";
    // printf("str1 is %s, str2 is %s", str1, str2);
    //swap(str1, str2);
    swap1(str1, str2);
    //printf("str1 is %s, str2 is %s", str1, str2);
    //getchar();
    return 0;
}
