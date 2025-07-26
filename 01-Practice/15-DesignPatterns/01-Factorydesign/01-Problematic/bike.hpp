#ifndef BIKE_HPP
#define BIKE_HPP

#include "../01-Factorydesign/vehicle.hpp"

class Bike: public Vehicle{
    public:
        void createVehicle();
};

#endif