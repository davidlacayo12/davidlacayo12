#include <iostream>
#include "cube.h"

using std::cout;
using std::endl;

namespace cs225 {
    Cube::Cube() {
        length_ = 1;
        cout << "Default Constructor" <<endl;
    }

    Cube::Cube(double length)    {       //constructor that takes in a double data type on initialization of Cube() 
        length_ = length;
    }
    double Cube::getVolume() const {       //:: is scope resolution operator --> signifies "things here are attached" -->need to include const if it is used in your method 
        return length_ * length_ * length_;
    }
    double Cube::getSurfaceArea() {
        return 6 * length_ * length_;
    }

    Cube::Cube(const Cube & other) {        //copy constructor
        length_ = other.length_;
    }

}
