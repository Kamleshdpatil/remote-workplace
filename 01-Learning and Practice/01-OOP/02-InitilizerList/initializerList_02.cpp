#include <iostream>
using namespace std;
 
class A {
    int i;
    int j;
public:
    //A(int, int);
    A(){
        cout<<"A's constructor\n"<<endl;
        cout<<"A's constructor value of i:\n"<<i<<endl;
        cout<<"A's constructor value of j:\n"<<j<<endl;
    }
};
 
// A::A(int arg, int arg1) {
//     i = arg;
//     j = arg1;
//     cout << "A's Constructor called: Value of i: " << i << endl;
//     cout << "A's Constructor called: Value of j: " << j << endl;
// }
 
// Class B contains object of A
class B {
    A a;
public:
    //B(int, int );
    B(){cout<<"B's constructor\n"<<endl;}
};
 
// B::B(int x, int y):a(x, y) {  //Initializer list must be used
//     cout<<endl;
//     cout << "B's Constructor called: Value of i: " << x << endl;
//     cout << "B's Constructor called: Value of j: " << y << endl;
// }
 
int main() {
    B obj;
    return 0;
}
/* OUTPUT:
    A's Constructor called: Value of i: 10
    B's Constructor called
*/