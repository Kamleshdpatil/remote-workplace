#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

void printArray(char arr[], int size)
{
    printf("\n");
    for(int i = 0; i < size; i++)
    {
        printf("Arr[%d]= %c\n", i, arr[i]);
    }
    printf("\n");
}

int main(void)
{
    char date[11];
    int mm, dd, yyyy;

    cout<<"Enter date: ";
    cin>>date;

    if(strlen(date) < 10 || strlen(date) > 10)
    {
        
    }
    else if(strlen(date) == 10)
    {
        char d[3], m[3], y[5];

        for(int i = 0; i<2; i++)
        {
            d[i] = date[i];
        }
        d[2]='\0';
        // Print date array
        printArray(d, 3);

        for(int i = 3, j=0; i<5; i++, j++)
        {
            m[j] = date[i];
        }
        m[2]='\0';
        printArray(m, 3);

        for(int i = 6, j = 0; i<10; i++, j++)
        {
            y[j] = date[i];
        }
        y[4]='\0';
        printArray(y, 5);

        dd = atoi(d);
        mm = atoi(m);
        yyyy = atoi(y);

        cout<<"\n Day : "<<dd;
        cout<<"\n Month : "<<mm;
        cout<<"\n Year : "<<yyyy;

    }
    else
    {
    cout<<"\n Error:Input should be in mm/dd/yyyy format";
    }
    return 0;
}

