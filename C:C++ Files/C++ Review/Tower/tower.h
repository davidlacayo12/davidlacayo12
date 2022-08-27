#pragma once

#include "../cube/cube.h"
using cs225::Cube;

class Tower {
    public: 
        Tower(Cube c, Cube *ptr, const Cube *ref);  //default constructor
        Tower(const Tower & other);             //copy constructor 

    private:
        Cube cube_;
        Cube *ptr_;
        const Cube &ref_;

};