#include<iostream>
#include<vector>
#include<chrono>

using namespace std;
using namespace std::chrono;

#define     BIKE                "Bike"
#define     CAR                 "Car"
#define     HANDICAPPED         "Handicapped"

// This class will work for every tyep of vehicle in this system
// It's method should be defined in every child(inheritated) class
class Payment
{
    public:
        virtual double calculateCost(double hours) = 0;
};


// Derived from Payement(Abstract base class)
// Implementation of Car Payment
class CarPayment: public Payment
{
    public:
        double calculateCost(double hours) {return(((hours * 2) + 10 )* 2);}
};

// Implementation of Bike Payment
class BikePayment: public Payment
{
    public:
        double calculateCost(double hours) {return(((hours * 2) + 10 )* 1);}
};

// Implementation of Handicapped vehicle Payment
class HandicappedPayment: public Payment
{
    public:
        double calculateCost(double hours) {return(0);}
};

// Generic class for all types of vehicles.
class Vehicle
{
    protected:     // Members are accessible for derived classes with protected keyward.
        Payment* payment;
        time_point<system_clock> parkedTime;  // Chrono header file's class object(std::chrono::system_clock::time_point)

    public:
        virtual string getType() = 0;  // Pure virtual function(Abstract method)

        // Will invoke this method as per the type object at run-time.
        virtual double calculateCost(double hours)
        {
            return(payment->calculateCost(hours));   // payment : Could be anything e.g. Bike payement object, Car Payement object etc.
        }

        // Set the Parking time once vehicle parked.
        void setParkedTime()
        {
            parkedTime = system_clock::now();  //std::chrono::system_clock
        }

        // Get the Parked time at the time of payment.
        time_point<system_clock> getParkedTime()
        {
            return(parkedTime);
        }
};

class Car: public Vehicle
{
    public:
        Car() // Defualt constructor
        {
            payment = new CarPayment();   // Creating object of Car Payment. payment is object member of class Vehicle.
        }

        // Overriding a method of class Vehicle.
        string getType() 
        {
            return(CAR);
        }
};

class Bike: public Vehicle
{
    public:
        Bike() // Defualt constructor
        {
            payment = new BikePayment();   // Creating object of Bike Payment. payment is object member of class Vehicle.
        }

        // Overriding a method of class Vehicle.
        string getType() 
        {
            return(BIKE);
        }
};

class HandicappedVehicle: public Vehicle
{
    public:
        HandicappedVehicle() // Defualt constructor
        {
            payment = new HandicappedPayment();   // Creating object of Handicapped Vehicle Payment. payment is object member of class Vehicle.
        }

        // Overriding a method of class Vehicle.
        string getType() 
        {
            return(HANDICAPPED);
        }
};

class Parkinglot
{
    private:
        // like 3-Dimentional Array.
        // spots[floors][rows][spotsPerRow];
        vector<vector<vector<Vehicle*>>> spots;  // Spot is a vector of Type Vehicle pointer's vector of vector.
        int floors;
        int rows;
        int spotsPerRow;

    public:

        // It will construct parking lot(area).
        Parkinglot(int floors, int rows, int spotsPerRow)
        {
            this->floors = floors;
            this->rows = rows;
            this->spotsPerRow = spotsPerRow;

            spots.resize(floors);  // Resizing with inputs of floors.
            for(int i = 0; i < floors; i++)
            {
                spots[i].resize(rows);  // Resizing with inputs of rows.
                for(int j = 0; j < rows; j++)
                {
                    spots[i][j].resize(spotsPerRow);  // Resizing with spotsPerRow of rows. e.g. spots[floors][rows][spotsPerRow];
                }
            }
        }

        bool park(Vehicle* vehicle, int floor, int row, int spot)
        {
            if(spots[floor][row][spot] == nullptr)
            {
                spots[floor][row][spot] = vehicle;
                cout<<vehicle->getType()<<" Parked Successfully at floor "<<floor<<", row "<<row<<", spot "<<spot<<"."<<endl;
                return true;
            }
            else
            {
                cout << "Spot already occupied." << endl;
                return false;
            }
        }

        bool leave(Vehicle* vehicle)
        {
            for(int i = 0; i < floors; i++)
            {
                for(int j = 0 ; j < rows; j++)
                {
                    for(int k = 0; k < spotsPerRow; k++)
                    {
                        if(spots[i][j][k] == vehicle)
                        {
                            double hours = calculateHoursParked(spots[i][j][k]);
                            double cost = spots[i][j][k]->calculateCost(hours);
                            spots[i][j][k] = nullptr;
                            cout << vehicle->getType() << " left successfully. Total cost: " << cost <<endl;
                            return true;
                        }
                    }
                }
            }

            cout << vehicle->getType() << " not found." << std::endl;
            return false;
        }

        int availableSpots(int floor)
        {
            int count = 0;
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < spotsPerRow; j++)
                {
                    if(spots[floor][i][j] == nullptr)
                    {
                        count++;
                    }
                }
            }
            return(count);
        }

        int handicappedSpots(int floor)
        {
            int count = 0;
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < spotsPerRow; j++)
                {
                    if(dynamic_cast<HandicappedVehicle*>(spots[floor][i][j]) != nullptr)
                    {
                        count ++;
                    }
                }
            }
            return(count);
        }

        double calculateHoursParked(Vehicle* vehicle)
        {
            for(int i = 0; i < floors; i++)
            {
                for(int j = 0; j < rows; j++)
                {
                    for(int k = 0; k < spotsPerRow; k++)
                    {
                        if(spots[i][j][k] == vehicle)
                        {
                            // Get the current time
                            auto now = system_clock::now();
                            // Get the parked time
                            auto parkedTime= spots[i][j][k]->getParkedTime();
                            auto duration = duration_cast<hours>(now - parkedTime);
                            return(duration.count());
                        }
                    }
                }
            }
            return 0;
        }
};

int main(void)
{
    Parkinglot lot(3, 4, 6);
    Car car1, car2;
    Bike bike1, bike2;
    HandicappedVehicle hv1;

    car1.setParkedTime();
    lot.park(&car1, 0, 0, 0);

    car2.setParkedTime();
    lot.park(&car2, 0, 0, 1);

    bike1.setParkedTime();
    lot.park(&bike1, 0, 0, 2);

    hv1.setParkedTime();
    lot.park(&hv1, 2, 9, 19);

    cout << "Available spots on floor 0: " << lot.availableSpots(0) << endl;
    cout << "Handicapped spots on floor 2: " << lot.handicappedSpots(2) << endl;

    lot.leave(&car1);
    lot.leave(&bike1);

    cout << "Available spots on floor 0: " << lot.availableSpots(0) << endl;

    return(0);
}
