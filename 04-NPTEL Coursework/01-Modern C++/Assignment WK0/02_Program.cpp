#include<iostream>
#include<stdio.h>

using namespace std;

enum Covid_prevention{
    Sani = 1,
    Wear_mak = 2,
    Soc_distance = 4
};

int main(void)
{
    int myCovid = Wear_mak | Soc_distance;

    printf("%d", myCovid);

    return(0);
}
