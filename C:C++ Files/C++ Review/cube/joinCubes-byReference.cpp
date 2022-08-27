#include <iostream>
#include <cmath>
#include "cube.h"
using std::cout;
using std::endl;
using cs225::Cube;

/*
    Creates a new Cube that contaisn the exact volume of the volume of the two input cubes
*/

Cube joinCubes(const Cube & c1, const Cube & c2) {      //using const makes your code safe when passing in references as objects
    double  totalVolume = c1.getVolume() + c2.getVolume();

    double newLength = std::pow(totalVolume, 1.0/3.0);

    Cube result(newLength);
    return result;

}

int main() {
    Cube *c1 = new Cube(4);
    Cube *c2 = new Cube(5);

    Cube c3 = joinCubes(*c1, *c2);
    cout << "c3.getVolume(): " << c3.getVolume() <<endl;

    return 0;
}