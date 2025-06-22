#include <iostream>

using namespace std;

int add(int = 0, int = 0);
double add(int = 0, double d = 0.0);

int main()
{
    int res = add();

    cout << "OK" << endl;
    return 0;
}
