#include"something.h"
#include<iostream>

using namespace std;

// Declaring the same variable
extern int iVar;
// int var;
// It will throw compiler error as compiler will get
// confused where the variable is defined
  
int main(void)
{
    cout<<iVar<<endl;
    return 0;
}