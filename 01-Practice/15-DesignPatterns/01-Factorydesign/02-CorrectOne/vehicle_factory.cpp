#include<iostream>
#include "../01-Factorydesign/"
#include"../01-Factorydesign/car.hpp"
#include"../01-Factorydesign/bike.hpp"

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