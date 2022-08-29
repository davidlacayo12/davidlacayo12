#include "square.h"
#include <iostream>

double Square::getArea() const{
    return getLength() * getLength();
}

Square::Square(double l) : Shape(l) {   //this is how you would be able to access length by creating a shape right on the stack using polymorphism
    //Method
}