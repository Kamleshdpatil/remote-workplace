#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
    int iArr[] = {10, 20, 50, 40, 10, 50};

    rotate(&iArr[0], &iArr[2], &iArr[6]);
    //
    //remove(&iArr[0], &iArr[6], 50);
    remove(iArr, iArr + 6, 50);

    for(int i = 0; i < 4; i++){
        cout<<iArr[i] <<" ";
    }
    
    return(0);
}
