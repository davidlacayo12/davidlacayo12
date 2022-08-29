#pragma once 

#include "shape.h"

class Square : public Shape {
    public:
        double getArea() const;
        Square(double l);
    private:
        //Nothing
};