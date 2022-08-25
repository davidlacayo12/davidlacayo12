#include <iostream>
#include "cube.h"
using std::cout;
using std::endl;
using cs225::Cube;
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

//using namespace std; //namespaces are groupings of classes, functions, etc. under a name -->using namespace std is a bad coding practice --> DONT DO THIS. Do them individually 
/*namespace example)

    namespace cs225 {
        class Cube{

        };
    }
*/

//Cube s1; -->creates a variable containing an instance of an object
//Cube & r1 = s1; --> a reference variable of a Cube object --> reference to the Cube s1 
//Cube * p1 = &s1; --> A variable containing a pointer to a Cube object --> p1 contaisn the address of a Cube 

/*Pointers
    1)  variable that contains an address
    2)  Resolve address to read data pointed to
    3)  powerful but DANGEROUS

    Indirection operators:
        Given any variable v:
            &v      address of operator: return address of v 
            *v      dereference operator: reads v and returns the value in the location v points to
            v->     follows the pointer and calls the function. p1->getVolume() same as: (*p1).getVolume() 
*/

int main() {
    cs225::Cube c(5.0);      //declares c as a local variable of type cs225::Cube, and takes in a double for the constructor
    cout << "Volume: " << c.getVolume() <<endl;
    std::cout<< "Address storing 'c': " << &c << std::endl;
    
    cs225::Cube *ptr = &c;
    std::cout << "Addr. storing ptr: " << &ptr << std::endl;
    std::cout << "Contents of ptr: " << ptr << std::endl;
    
    return 0;
}