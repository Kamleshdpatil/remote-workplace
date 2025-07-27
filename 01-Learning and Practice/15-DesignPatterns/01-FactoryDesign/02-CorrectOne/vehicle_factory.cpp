#include<iostream>
#include "vehicle_factory.hpp"
#include"car.hpp"
#include"bike.hpp"

using namespace std;

Vehicle* VehicleFactory::getVehicle(string vehicleType){
    Vehicle* vehicle;
    if(vehicleType == "car")
        vehicle = new Car();
    else if(vehicleType == "bike")
        vehicle = new Bike();
    else
        cout<<"Unknown type"<<endl;
    
    return vehicle;
}