#include<iostream>

using namespace std;


// vector<int> vec;
// map<char, int> mp;

// // end program

// pwd - 
// whoami - 
// ls -all
// touch - new file
// mkdir 
// rmdir 
// mv

// git clone ""
// git checkout -b newBrach;

// git commit -m ""

// git push

// 
//




class base
{
    int data; // data abstraction
    public:
        base()
        {
            data = 10;
        }

        //copy const
        base(const base& obj)
        {
            // we cann our
            data = obj.data;
        }
        template<typename T>
        void show(T i){}; //
        

        // void show(float ivalue, float ivalue2)
        // {
        //     cout<<data + ivalue + ivalue2<<endl;
        // }
};

class derived: public base{
    public:
        // void show(int ivalue, int ivalue2)
        // {
        //     cout<<"Inside derived: "<<ivalue * ivalue2<<endl;
        // }



};

void fun()
{
    cout<<"Hello world!"<<endl;
}

// +

int main(void)
{

    base obj;
    //obj.show();

    base obj2(obj);

    //obj2.show();

    void (*f)()= &fun;

    f();


    // // obj.show(10, 20);
    // // obj.show((float)10.10, (float)20.05);

    // base* b = new derived();

    // b->show(2,3);

    return(0);
}
