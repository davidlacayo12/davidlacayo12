#include <iostream>
#include "cube.h"
#include <cmath>

using std::cout;
using std::endl;

namespace cs225 {
    Cube::Cube() {      //default constructor 
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

    Cube joinCubes(const Cube & c1, const Cube & c2) {      //using const makes your code safe when passing in references as objects
        double  totalVolume = c1.getVolume() + c2.getVolume();

        double newLength = std::pow(totalVolume, 1.0/3.0);

        Cube result(newLength);
        return result;

}

    Cube Cube::operator+(const Cube & r) const{     //second const is saying--> *this
        return joinCubes(*this, r);
    }

    Cube::~Cube() {     //automatic destructor
        cout << "destructor" <<endl;
        //example: delete foo_; <-- prevent leak
    }

}
