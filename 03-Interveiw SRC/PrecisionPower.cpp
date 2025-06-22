// 
#include<iostream>
using namespace std;

// Fill array
void fillArray(int *arr, int height, int width){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            arr[i * width +j] = i+j;
        }
    }
}

// Print array
void printArray(int *arr, int height, int width){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout<<arr[i * width +j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int iArr2D[5][10];
    fillArray(&iArr2D[0][0], 5, 10);
    printArray(&iArr2D[0][0], 5, 10);

    cout<<endl;
    cout<<"Second array"<<endl;

    int iArr1D[5];
    fillArray(&iArr1D[0], 5, 10);
    printArray(&iArr1D[0], 5, 10);
    
    return 0;
}