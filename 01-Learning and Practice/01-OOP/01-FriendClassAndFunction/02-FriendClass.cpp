#include<iostream>

using namespace std;

class Akshay{
    int id;
    public:
    void setId(int iNum){
        id = iNum;
    }
    void showId(){
        cout<<"Akshay's ID: "<<id<<endl;
    }

    friend class Shiva;
};

class Shiva{
    public:
    void setAk(Akshay& aObj){
        aObj.id = 1000;
        cout<<"Id Set from Shiva"<<endl;
    }
    void Display(Akshay& aObj){
        cout<<"Akshay's ID From Shiva's Object: "<<aObj.id<<endl;
    }
};

int main()
{
    Akshay aObj;
    Shiva sObj;

    aObj.setId(10);
    aObj.showId();

    sObj.Display(aObj);
    sObj.setAk(aObj);
    sObj.Display(aObj);

    return(0);
}
