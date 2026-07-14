#include<iostream>
#include<stdexcept>

using namespace std;

void checkAge(int age)
{
    if(age < 18){
        throw invalid_argument("Access denied !!");
    }
    cout<<"Access granted. Welcome !!";
}

int main()
{
    int userAge = 10;

    // checkAge(userAge);

    try{
        checkAge(userAge);
    }catch(const invalid_argument& e){
        //cout<<"Error: "<<e.what()<<endl;
        cerr<<"Error: "<<e.what()<<endl;
    }catch(...){
        cerr<<"An exception occured."<<endl;
    }

    cout<<"Program execution ended !!"<<endl;

    return 0;
}
