#include<iostream>
#include<stdio.h>

using namespace std;

class Solution {
public:

};

int main(void)
{
    typedef double num[3];
    num array[5] = {1,2,3,4,5,6};

    printf("%u", sizeof(array));

    printf(" %.2f", array[1][1]);

    //cout<<"Hello World!"<<endl;
    return(0);
}
