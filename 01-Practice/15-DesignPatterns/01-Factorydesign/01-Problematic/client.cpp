#include<iostream>
#include"../01-Factorydesign/bike.hpp"
#include"../01-Factorydesign/car.hpp"

using namespace std;

int main()
{
    Vehicle* vehicle;
    string vehicleType;
    cout<<"Enter vehicle type: "; 
    cin>>vehicleType;
    cout<<endl;

    if(vehicleType == "car")
        vehicle = new Car();
    else if(vehicleType == "bike")
        vehicle = new Bike();

    vehicle->createVehicle();
    
    return (0);
}