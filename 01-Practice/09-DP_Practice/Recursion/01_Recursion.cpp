/*
 Print 3 to 1
*/

#include<iostream>
#include<stdio.h>

static int cnt = 0;

void fun(int n)
{
    printf("fun: Enter\n");
    if(cnt == 3)
    {
        return;
    }
    cnt++;
    fun(n);
    printf("cnt: %d\n", cnt--);
}

int main(void)
{
    void fun(int);
    int count = 0;

    fun(count);

    return(0);
}