#include <iostream>
#include "cube.h"

//Use nullptr instead of NULL from now on-- better coding practice and a keyword in C++ 
//macros are ALWAYS capatalized --> EX) #define COUNT 5 
/*Encapsulation is the process of separating the interface from the implementation (in terms of classes)
    Interface is HOW it is used (example of an interface would be an array)
    Implementation is how it works to function (How you actually DO it)
    Encapsulation breaks a program down into multiple files 
        header file: contains the interface, and describes how you access and use a class (tells people HOW to use the code)
        code file (or C++ file): implementation  (How code is implemented)
*/
/*Constructor
    Compiler provides 'Default constructor' 
    zero args
*/

using namespace std; //namespaces are groupings of classes, functions, etc. under a name 
/*namespace example)

    namespace cs225 {
        class Cube{

        };
    }
*/



int main() {
    cs225::Cube c(5.0);      //declares c as a local variable of type cs225::Cube, and takes in a double for the constructor
    std::cout << "Volume: " << c.getVolume() <<std::endl;
    return 0;
}