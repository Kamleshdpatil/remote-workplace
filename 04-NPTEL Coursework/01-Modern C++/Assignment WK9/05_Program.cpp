#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream myfile("myfile.txt");
    char c;
    int i = 0;
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            myfile >> c;
            // c = myfile.get();
            //  myfile.get(c);
            if (c == ' ')
            {
                i++;
            }
        }
        myfile.close();
        cout << "characters: " << i;
    }
    else
    {
        cout << "Unable to open file";
    }

    return 0;
}
