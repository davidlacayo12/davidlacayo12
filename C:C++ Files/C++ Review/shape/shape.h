#pragma once
#include <iostream>

class Shape {
    public:
        Shape();
        Shape(double length);
        double getLength() const;

    private:
        double length_;
        
};