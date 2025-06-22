#include<iostream>
#include<stdio.h>

using namespace std;

enum Covid_prevention{
    Sani = 1,
    Wear_mak = 2,
    Soc_distance = 4
};

union uData{
    int a;
    int b;
};

struct sData
{
    union uData c;
    int d;
};



int main(void)
{
    struct sData da = {10,20};
    
    printf("%ld \n", sizeof(da));
    
    printf("%d %d %d", da.c.a, da.c.b, da.d);
    // int myCovid = Wear_mak | Soc_distance;

    // //printf("%d", myCovid);

    // int x = 1;
    // int y;

    // //y=(x=x+5, x*5);
    // y=(x=x+5, x*2);

    // printf("X: %d\n", x);
    // printf("%d", y);

    // int x=8, y, z;
    // y= --x;
    // printf("%d %d %d\n", x,y,z);
    // z= x--;
    // printf("%d %d %d", x,y,z);

    return(0);
}
