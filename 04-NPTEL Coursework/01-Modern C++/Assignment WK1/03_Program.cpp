#include<iostream>
#include<algorithm>

using namespace std;

void modify(int *arr){
    cout<<"Initialy: "<<endl;
    for(int i = 0; i < 5; i++){
        cout<<*(arr + i) <<" ";
    }
    rotate(arr, arr + 3, arr + 5);
    cout<<endl;
    cout<<"After first rotate: "<<endl;
    for(int i = 0; i < 5; i++){
        cout<<*(arr + i) <<" ";
    }
    cout<<endl;

    rotate(arr, arr + 2, arr + 4);
    cout<<"After second rotate: "<<endl;
    for(int i = 0; i < 5; i++){
        cout<<*(arr + i) <<" ";
    }
    cout<<endl;
}

int main(void)
{
    int iarr[5];
    for(int i = 0; i < 5; i++){
        *(iarr + i) = i + 1;
    }
    modify(iarr);

    cout<<endl;

    for(int i = 0; i < 5; i++){
        cout<<*(iarr + i) <<" ";
    }
    
    return(0);
}
