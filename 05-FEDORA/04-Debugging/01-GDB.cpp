#include<iostream>
#include<vector>

using namespace std;

void processData(int* ptr){
    for(int i = 0; i < 12; i++)
    {
        ptr[i] = i+1;
    }
}

void printData(int* ptr){
    cout<<"Value: ";
    for(int i = 0; i < 12; i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int* data = new int[8];

    processData(data);
    // delete[] data;
    printData(data);

    return(0);
}

