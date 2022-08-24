#include <iostream>
#include "cube.h"

using namespace std;
namespace cs225 {
    Cube::Cube(double length)    {       //constructor that takes in a double data type on initialization of Cube()
        length_ = length;
    }
    double Cube::getVolume(){       //:: is scope resolution operator --> signifies "things here are attached"
        return length_ * length_ * length_;
    }
    double Cube::getSurfaceArea() {
        return 6 * length_ * length_;
    }
}
