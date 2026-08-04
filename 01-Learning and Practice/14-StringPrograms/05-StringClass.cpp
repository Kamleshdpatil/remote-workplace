//
// String class implementation
//
#include<iostream>

using namespace std;

class String{
    char* str;   // data buffer
    int len;    // length of data buffer

    public:
    // Friend Function to print using cout<<
    friend ostream& operator<<(ostream& os, const String& obj);

    // to get the size
    int size(){return len;}

    // Constructor with constant literal
    String(const char* s)
    {
        if(s)
        {
            int iLen = 0;
            int i = 0;
            while(s[i++] != '\0')
            {
                iLen++;
            }

            len = iLen;
            str = new char[len+1];
            for(i = 0; i < len; i++)
            {
                str[i] = s[i];
            }
            str[len] = '\0';
        }
        else{
            len = 0;
            str = new char[1]{'\0'};
        }
    }

    // Constructor with Size and constant literal
    String(int iSize, const char* s) : len(iSize)
    {
        if(s && len > 0){
            int iLen = 0;
            int i = 0;
            while(s[i++] != '\0')
            {
                iLen++;
            }

            str = new char[iSize + 1];
            for(i = 0; i < iLen; i++)
            {
                str[i] = s[i];
            }
            str[iLen] = '\0';
            len = iSize;
        }
        else{
            len = 0;
            str = new char[1]{'\0'};
        }
    }

    // Copy Constructor - Deep
    String(const String& obj) : len(obj.len)
    {
        if(obj.str && len > 0)
        {
            str = new char[obj.len + 1];
            for(int i = 0; i < len; i++)
            {
                str[i] = (obj.str)[i];
            }
            str[len] = '\0';
        }
        else{
            len = 0;
            str = new char[1]{'\0'};
        }
    }

    // Copy Assignment Constructor
    String& operator=(const String& obj)
    {
        if(this == &obj)
            return *this;

        delete[] str;
        if(obj.str && obj.len > 0)
        {
            len = obj.len;
            str = new char[obj.len + 1];
            for(int i = 0; i < len; i++)
            {
                str[i] = (obj.str)[i];
            }
            str[len] = '\0';
        }
        else{
            len = 0;
            str = new char[1]{'\0'};
        }
        return *this;
    }

    // Move Constructor
    String(String&& obj)
    {
        len = obj.len;
        str = obj.str;

        obj.len = 0;
        obj.str = nullptr;
    }

    // Move Assignment Constructor
    String& operator=(String&& obj)
    {
        if(this == &obj)
            return *this;

        delete[] str;
        len = obj.len;
        str = obj.str;

        obj.len = 0;
        obj.str = nullptr;

        return *this;
    }

    // Concatination
    String operator+(const String& obj) const
    {
        int newLen = (this->len + obj.len);
        
        String result(newLen, "");
        
        int i = 0;
        for(i = 0; i < this->len; i++)
        {
            result.str[i] = this->str[i];
        }
        for(int j = 0; j < (obj.len); i++, j++)
        {
            result.str[i] = obj.str[j];
        }

        result.str[newLen] = '\0';

        return result;
    }



    void print()
    {
        for(int i = 0; i < len; i++)
        {
            cout<<str[i];
        }
        cout<<"\n";
    }

    ~String(){ delete[] str;}

};

ostream& operator<<(ostream& os, const String& obj)
{
    if (obj.str)
    {
        os << obj.str;
    }
    return os;
}

int main()
{
    String str = String(7, "Kamlesh");

    String str1("Gouri");

    
    // cout<<"---- Str -----\n"; 
    // cout<<"Size of str: "<<str.size()<<endl;
    // cout<<"Data of Buffer: ";
    // str.print();
    
    // cout<<"\n---- Str1 -----\n"; 
    // cout<<"Size of str1: "<<str1.size()<<endl;
    // cout<<"Data of Buffer: ";
    // str1.print();

    // String str2(str);
    // cout<<"\n---- str2 -----\n"; 
    // cout<<"Size of str2: "<<str2.size()<<endl;
    // cout<<"Data of Buffer: ";
    // str2.print();

    // String str3 = str1;
    // cout<<"\n---- str3 -----\n"; 
    // cout<<"Size of str3: "<<str3.size()<<endl;
    // cout<<"Data of Buffer: ";
    // str3.print();

    String str4 = str + " " + str1;
    cout<<"\n---- str4 -----\n"; 
    cout<<"Size of str4: "<<str4.size()<<endl;
    cout<<"Data of Buffer: ";
    str4.print();

    cout<<" --- Print --- \n";
    cout<<str4<<endl;

    return(0);
}
