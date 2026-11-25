#include<iostream>
#include<fstream>

using namespace std;

void write_file(){
    ofstream file("demo_RAII.txt");
    file<<"Hellow World!!";
}

int main(void)
{
    write_file();

    return(0);
}
