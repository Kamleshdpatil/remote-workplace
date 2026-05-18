#include <iostream>

using namespace std;

// Funation Overloading
class Math{
    public:
    int addition(int iNum1, int iNum2)
    {
        cout<<"First varient of add()"<<endl;
        return (iNum1 + iNum2);
    }
    int addition(int iNum1, int iNum2, int iNum3)
    {
        cout<<"Second varient of add()"<<endl;
        return (iNum1 + iNum2 + iNum3);
    }
    int addition(int iNum1, int iNum2, double iNum3)
    {
        cout<<"Third varient of add()"<<endl;
        return (iNum1 + iNum2 + (int)iNum3);
    }
};

// Operator Overloading
class Money{
    private:
    
    double ammount;
    string currency;

    public:
    Money(double dAmmount, string sCurrency) : ammount(dAmmount), currency(sCurrency){

    }

    double getAmmount(){
        return ammount;
    }

    string getCurrency(){
        return currency;
    }

    // + Operator overloading
    Money operator+(const Money& other){
        if(other.currency != currency)
            throw runtime_error("Currency Mismatch !!\n");
        
        return Money(ammount + other.ammount, currency);
    }

    // + Operator overloading
    Money operator-(const Money& other){
        if(other.currency != currency)
            throw runtime_error("Currency Mismatch !!\n");
        
        return Money(ammount - other.ammount, currency);
    }

    // << Operator overloading
    friend ostream& operator<<(ostream& os, const Money& other){
        os<<other.currency<<" "<<other.ammount;
        return os;
    }

    void display() const{
        cout<<"Currency: "<<currency<<" Ammount: "<<ammount<<endl;
    }
    
};
int main()
{
    Money salary(78000, "INR");
    Money bonus(12000, "INR");
    Money servrity(15000, "INR");

    Money total = salary + bonus + servrity;
    Money remaining = total - Money(12000, "INR");

    total.display();
    remaining.display();

    cout<<remaining<<endl;

    return 0;
}
