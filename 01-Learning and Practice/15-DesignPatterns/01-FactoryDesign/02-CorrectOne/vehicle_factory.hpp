#ifndef VEHICLE_FACTORY_HPP
#define VEHICLE_FACTORY_HPP

#include<iostream>
#include"vehicle.hpp"

using namespace std;

class VehicleFactory{
    public:
        static Vehicle* getVehicle(string);
};

#endif
