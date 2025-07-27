#include<iostream>

using namespace std;

class MyString
{
        // Initialize dynamic char array
        char* str;

    public:
        // No Arguments 
        MyString();

        // With 1argument
        MyString(char* val);

        // Copy constructor
        MyString(const MyString& source);

        // Move Constructor
        MyString(MyString&& source);

        virtual ~MyString(){delete str;}

        int strLength(char* str);
        void strCopy(char* str1, char* str2);
};

int main(void)
{
    char temp[] = "Kamlesh";
    //MyString b{temp};

    MyString a;

    MyString b{a};

    //cout<<b<<endl;

    MyString d{MyString {temp}};
    
    return(0);
}

MyString::MyString():str{nullptr}
{
    str = new char[1];
    str[0] = '\0';
}

MyString::MyString(char* val)
{
    if(val == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        str = new char[strLength(val) + 1];
        strCopy(val, str);
    }
    cout<<"\nString Recived: "<<val<<endl;
}

MyString::MyString(const MyString& source)
{
    str = new char[strLength(source.str) + 1];
    strCopy(str, source.str);
}

// Function to illustrate
// Move Constructor
MyString::MyString(MyString&& source)
{
    str = source.str;
    source.str = nullptr;
}

int MyString::strLength(char* str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return(len);
}

void MyString::strCopy(char* source, char* desti)
{
    for(int i = 0; i < strLength(source); i++)
    {
        desti[i] = source[i];
    }
    desti[strLength(source)] = '\0';
}
