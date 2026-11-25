#include <iostream>

using namespace std;

class Vehicle
{
public:
    string company;
    string model;
    string varient;
    string fuleType;
    int enginePower;
    int wheelCount;
    int seatCapacity;

public:
    virtual void showVehicleInfo() = 0;

    virtual ~Vehicle(){}
};

class FourWheeler : public Vehicle
{
public:
    FourWheeler()
    {
        wheelCount = 4;
    }
    void showVehicleInfo()
    {
        cout << "--- FourWheeler Details---" << endl;
        cout<<"Wheel Count: "<<wheelCount<<endl;
    }
};

class Car : public FourWheeler
{
    public:
    Car(string company, string model, string varient,
    string fuleType, int enginePower, int seatCapacity)
    {
        this->company = company;
        this->model = model;
        this->varient = varient;
        this->fuleType = fuleType;
        this->enginePower = enginePower;
        this->seatCapacity = seatCapacity;
    }
    void showVehicleInfo()
    {
        cout << "--- Vehicle Details---" << endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Varient: "<<varient<<endl;
        cout<<"Fule Type: "<<fuleType<<endl;
        cout<<"Engine Power: "<<enginePower<<endl;
        cout<<"Wheel Count: "<<wheelCount<<endl;
        cout<<"Seat Capacity: "<<seatCapacity<<endl<<endl;
    }
};

int main()
{
    Vehicle* vPtr;
    Car carObj("TATA", "Creative+ PS DT", "Top Varient with Sunroof", "CNG + Petrol", 170, 5);
    cout<<sizeof(carObj)<<endl;
    vPtr = &carObj;

    vPtr->showVehicleInfo();

    FourWheeler fObj;
    vPtr = &fObj;

    vPtr->showVehicleInfo();

    return 0;
}
