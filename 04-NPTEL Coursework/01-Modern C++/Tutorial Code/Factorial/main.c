// Application of factorial function

#include <stdio.h>
#include "fact.h"

int main()
{

    int n, f;
    printf("Input n: ");
    scanf("%d", &n);

    f = fact(n);

    printf("fact(%d) = %d", n, f);

    return 0;
}
