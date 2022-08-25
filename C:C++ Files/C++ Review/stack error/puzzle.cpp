#include "cube.h"
using cs225::Cube;  

Cube *CreateCube() {
    Cube c(20);
    return &c;
}

int SomeOtherFunction() {
    return 0;
}

int main() {
    Cube *c = CreateCube();
    SomeOtherFunction();    //problem occurs here  --> from here on out, SomeOtherFunction() has written over the memroy of CreateCube(). Memory is released when function returns.
    double c = c->getVolume();
    double a = c->getSurfaceArea();
    return 0;

}   
//best solution is to use heap memory instead of stack --> starts low in memory, and grows UP from start
//stack starts high and grows down

/*Heap Memory --> declared using keyword 'new'
    1)  allocate memory on the heap <-- shared with behavior in c (malloc)
    2)  call constructor in memory 
    3)  r the address of allocated memory 

    only way to free heap memory is with the keyword 'delete'
        1)  Invokes Destructor  (cleans up class)
        2)  Deallocates memory 
    ** Memory is never automatically reclaimed, even if it goes out of scope. Any memory lost, but not freed is considered to be "leaked memory" **
        - Every new must be matched with a delete
*/