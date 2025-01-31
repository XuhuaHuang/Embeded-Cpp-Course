/*****************************************************************//**
 * \file   sequence_destruction.cpp
 * \brief  Sequence of destructor called
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>

class Vehicle {
public:
    ~Vehicle() {
        std::cout << "Vehicle" << "\n";
    }
};

class Engine {
public:
    ~Engine() {
        std::cout << "Engine" << "\n";
    }
};

class Truck : public Vehicle {
public:
    ~Truck() {
        std::cout << "Truck" << "\n";
    }
private:
    Engine engine;
};

int main()
{
    Truck truck;
    /**
     * `truck` goes out of the scope
     * Destructor called in such sequence:
     * Derived class destructor         -> "Truck"
     * Private data member destructor   -> "Engine"
     * Base class destructor.           -> "Vehicle"
     */

    return 0;
 }