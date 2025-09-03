#include <iostream>
using namespace std;

// Implement a function to split a string by a delimiter (e.g., ".", ",", or ";").

int main() 
{
    string str = "Hi, Kamlesh. How.. are, you ?";
    cout<<"Str: "<<str.length()<<endl;
    string output = "";
    int i = 0, offset = 0;
    int cnt = 0;
    for(i = 0; i < str.length(); i++)
    {
      if(str[i] == '.' || str[i] == ',' || str[i] == ' ')
      {
        // if(output.length() > 0){output +=" ";}
        
        output += str.substr(offset, i-offset);
        offset = i;
        // cout<< "output length: "<<output.length()<< " output: "<<output <<" offset: "<<offset<<endl;
      }
      
      if(str[i] == '.' || str[i] == ','){
        offset++;
      }
    }
    cout<<endl;
    cout<< output <<endl;

    return 0;
}
