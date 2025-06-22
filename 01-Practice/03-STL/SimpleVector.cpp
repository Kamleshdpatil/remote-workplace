#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;


int main()
{
    void Display(vector<int>);
    vector<int> vecInt;
    vecInt.push_back(10);
    vecInt.push_back(20);
    //vecInt.pop_back();

    printf("%d \t", vecInt.at(1));

    //Display(vecInt);

    return(0);
}

void Display(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        //cout<<vec[i]<<"\t"<<endl;
        printf("%d \t", vec.at(i));
    }
}