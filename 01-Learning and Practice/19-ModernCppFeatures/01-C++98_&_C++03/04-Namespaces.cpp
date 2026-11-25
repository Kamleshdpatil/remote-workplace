#include<iostream>
#include<fstream>

using namespace std;

// namespace
namespace FileOperations{
    void write_file(){
        ofstream file("demo_RAII.txt");
        file<<"Hellow World!!";
    }
}

int main(void)
{
    // FileOperations::write_file();
    
    {
        using namespace FileOperations;
        write_file();
    }

    return(0);
}
