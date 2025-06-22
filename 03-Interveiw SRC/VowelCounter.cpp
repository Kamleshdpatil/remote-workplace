#include<iostream>

using namespace std;

int GetVowelCount(char* str, int size)
{
    int count = 0;
    
    while (*str != '\0')
    {
        *str = tolower(*str);
        if(*str == 'a' || *str == 'e' ||*str == 'i' ||*str == 'o' ||*str == 'u')
            count++;

        str++;
    }
    
    return(count);
}


int main(void)
{
    //char str[] = {"Kamlesh Dugade Patil"};
    char str[] = {"AADisplay the count for vowels in a given character array and the array should be taken using character pointer."};
    int size = sizeof(str) / sizeof(str[0]);

    cout<<size<<endl;

    cout<<"Occurances of 2's : "<<GetVowelCount(str, size)<<endl;
    return(0);
}