#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
    int idata[] = {1, 2, 3, 4, 5};

    int n = sizeof(idata)/ sizeof(*idata);

    for(int i = 0; i < n/2; i++){
        int temp = idata[i];
        replace(idata, idata + 5, temp, *(idata + n - i - 1));
        replace(idata + i + 1, idata + 5, idata[n - i - 1], temp);
    }

    for(int i = 0; i < 5; i++){
        cout<<idata[i] <<" ";
    }
    
    return(0);
}
