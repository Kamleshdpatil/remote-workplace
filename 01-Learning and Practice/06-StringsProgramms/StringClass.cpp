#include<iostream>
#include<cstring>

using namespace std;

class String{
    char* data;
    int len;
    
    public:
    // Default constructor
    String():data(new char[1]{'\0'}), len(0){}

    // Parameterized constructor
    String(const char* str){
        len = strlen(str);
        data = new char[len+1];
        strcpy(data, str);
    }

    // Copy constructor
    String(const String& obj){
        len = strlen(obj.data);

        data = new char[len+1];
        strcpy(data, obj.data);
    }
    
    // Copy Assignement constructor
    String& operator=(const String& obj){
        if(this != &obj){
            len = strlen(obj.data);
            delete[] data; // free old memory
            
            data = new char[len+1];
            strcpy(data, obj.data);
        }
        return *this;
    }

    // Move constructor
    String(String&& obj) noexcept : data(obj.data), len(obj.len){
        obj.len = 0;
        obj.data = nullptr;
    }
    
    // Move Assignement constructor
    String& operator=(String&& obj) noexcept{
        if(this != &obj){
            delete[] data;

            len = obj.len;            
            data = obj.data;

            obj.len = 0;
            obj.data = nullptr;
        }
        return *this;
    }

    // Concatination handler constructor
    String operator+(const String& other){
        String temp;

        temp.len = len + other.len;
        temp.data = new char[temp.len + 1];
        strcpy(temp.data, data);
        strcat(temp.data, other.data);

        return temp;
    }

    // Get lnegth of string
    size_t length() const{
        return len;
    }
    
    // Support substrict operator
    char& operator[](const int index){
        if(index < 0 || index >= len)
            throw out_of_range("Index out of bounds");
            
        return data[index];
    }
    
    // Support substrict operator
    const char& operator[](const int index) const{
        if(index < 0 || index >= len)
            throw out_of_range("Index out of bounds");

        return data[index];
    }

    // String comparison
    bool operator==(const String& other) const{
        return !strcmp(data, other.data);
    }
    
    virtual ~String(){
        delete[] data;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str){
        os<<str.data;
        return os;
    }
};

int main()
{
    String s1("Hello");
    String s2("Kamlesh");

    // String s3 = s1 + s2;

    // std::cout << "S1: " << s1 << "\n";
    // std::cout << "S2: " << s2 << "\n";
    // std::cout << "S3: " << s3 << "\n";
    // std::cout << "Length of S3: " << s3.length() << "\n";

    // String s4 = move(s2);
    // std::cout << "S4: " << s4 << "\n";

    // String s5("Dugade");
    // std::cout << "S5: " << s5 << "\n";
    
    // s5 = move(s1);
    // std::cout << "S5: " << s5 << "\n";

    // cout<<s1[0]<<endl;
    // cout<<s1[1]<<endl;
    // cout<<s1[2]<<endl;
    // cout<<s1[3]<<endl;
    // cout<<s1[4]<<endl;

    String s6("Kamlesh");

    if(s6 == s2)
        cout<<"Same string"<<endl;
    else
        cout<<"Different string"<<endl;
    
    return(0);
}
