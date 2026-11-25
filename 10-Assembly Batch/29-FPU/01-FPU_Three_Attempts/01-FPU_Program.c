#include<stdio.h>

float fNo1 = 57.33f;
double dNo1 = 58963.546;

float fNo2;
double dNo2;

int main()
{
    printf("fNo1 = %f\tfNo2 = %f\n", fNo1, fNo2);
    printf("dNo1 = %lf\tdNo2 = %lf\n", dNo1, dNo2);

    fNo2 = fNo1;
    dNo2 = dNo1;

    printf("fNo1 = %f\tfNo2 = %f\n", fNo1, fNo2);
    printf("dNo1 = %lf\tdNo2 = %lf\n", dNo1, dNo2);

    return(0);
}
