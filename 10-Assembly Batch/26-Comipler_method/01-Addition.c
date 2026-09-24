#include<stdio.h>

int addition(int num1, int num2)
{
 int ans;
 ans = num1 + num2;
 return ans;
}

int main(void)
{
 int no1, no2;
 int ans;
 
 printf("Enter two numbers: \t");
 scanf("%d %d", &no1, &no2);
 
 ans = addition(no1, no2);
 
 printf("Addition: %d\n", ans);
 
 return 0;
}
