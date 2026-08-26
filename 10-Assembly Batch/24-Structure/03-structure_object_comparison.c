#include<stdio.h>
#include<stdlib.h>

struct demo
{
    char chChar;
    int iNo;
    short int shiNo;
} obj1 = {'A', 10, 20};

// one byte moment
// object memory reading optimizations


int main()
{
    struct demo obj2 = {'B', 30, 40};
    struct demo obj3 = {'B', 30, 40};

    printf("Obj1 is: \n");
    printf("chChar = %c, iNo = %d, shiNo = %hd\n\n", obj1.chChar, obj1.iNo, obj1.shiNo);

    printf("Obj2 is: \n");
    printf("chChar = %c, iNo = %d, shiNo = %hd\n\n", obj2.chChar, obj2.iNo, obj2.shiNo);

    printf("Obj3 is: \n");
    printf("chChar = %c, iNo = %d, shiNo = %hd\n\n", obj3.chChar, obj3.iNo, obj3.shiNo);

    printf("obj1 & obj2 comparision is: ");
    if(obj1.chChar == obj2.chChar && obj1.iNo == obj2.iNo && obj1.shiNo == obj2.shiNo)
        printf("equal\n");
    else
        printf("not equal\n");
    
    printf("obj3 & obj2 comparision is: ");
    if(obj3.chChar == obj2.chChar && obj3.iNo == obj2.iNo && obj3.shiNo == obj2.shiNo)
        printf("equal\n");
    else
        printf("not equal\n");

    exit(0);
}
