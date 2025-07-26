#include<iostream>
#include"../01-Factorydesign/vehicle_factory.hpp"

using namespace std;

int main()
{
    string vehicleType;
    cout<<"Enter vehicle type: "; 
    cin>>vehicleType;
    cout<<endl;
    
    Vehicle* vehicle = VehicleFactory::getVehicle(vehicleType);
    
    vehicle->createVehicle();
    
    return (0);
}