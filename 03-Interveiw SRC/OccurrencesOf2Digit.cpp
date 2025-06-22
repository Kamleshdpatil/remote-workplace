#include<iostream>

using namespace std;

int GetCount(int num, int find)
{
    int count = 0;
    while(num > 0)
    {
        if(num % 10 == find)
            count++;
        num = num /10;
    }
    return(count);
}

int FindOccurances(int range, int find)
{
    int count = 0;
    for(int i = find; i <= range; i++)
    {
        count = count + GetCount(i, find);
    }
    return(count);
}

int main(void)
{
    int num = 0;
    cin>>num;
    cout<<"Occurances of 2's : "<<FindOccurances(num, 2)<<endl;
    return(0);
}