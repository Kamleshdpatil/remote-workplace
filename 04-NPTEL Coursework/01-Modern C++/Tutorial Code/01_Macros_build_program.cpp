// Application file
#include <iostream>

using namespace std;

#if 0
#define TABLE_SIZE 100
int iArr[TABLE_SIZE];
#undef TABLE_SIZE

#define TABLE_SIZE 200
int iArr2[TABLE_SIZE];

#define str(x) #x
#define glue(a, b) a##b

// void printFlag()
// {
//     cout << (FLAG == 1) << endl;
// }

void printHashMacro()
{
    cout << str(test) << endl;
}
void printGlueMacro()
{
    cout << glue(c, out) << "best" << endl;
}
#endif

int main()
{
#if 0
    cout << "Sizeof iArr: " << sizeof(iArr) << endl;
    cout << "Sizeof iArr2: " << sizeof(iArr2) << endl;

    printFlag();
    printHashMacro();
#endif

#ifdef _DEBUG
    cout << "Debug wala code !!" << endl;
#endif

#ifndef _BITS32
    cout << "x64 Bit code !!" << endl;
#else
    cout << "x32 Bit code !!" << endl;
#endif

    return 0;
}
