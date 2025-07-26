#ifndef CAR_HPP
#define CAR_HPP

#include "../01-Factorydesign/vehicle.hpp"

class Car: public Vehicle{
    public:
        void createVehicle();
};

#endif