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

/*Using const
    - const modifies a type in general and says that it can't be changed 
    - example is in joinCubes-byRef-const.cpp
*/

/* Copy Constructor
    - makes a copy of the object of the class 
    - Cube c1(5); 
    - Cube c2 = c1; copy constructor
    - Cube c3; default constructor 
    - c3 = c1; --> assignment 
    - Cube c2(c1); copy constructor 3

    Copy constructor:    ONLY ONE PER CLASS 
        - Automatic Copy constructor
            - Make a new object of type that is initialized by calling the copy constructor on every member variable 
        
        - Custom Copy constructor 
            Cube(const Cube & other)    HAS TO BE A REFERENCE 
*/          

/* Destructor: 
    - Purpose: To release any resources allocated by the object 
    - Run on either delete or when a stack allocated object leaves scope 

    - Automatic Destructor: 
        - Exists only when no custom destructor is defined 
        - Invoked --> stack objects leaves scope, or on delete 
        - Functionality --> calls the destructor on each member variable 

*/

/* Overloading 
    -Operators that can be overlaoded in C++: +, -, *, /, %, ++, --, &, |, ^, ~, <<, >>, =, ==, !=, >,<, >=, <=, !, &&, ||, [], (), ->
    - Definition Syntax(.h) --> Cube & operator = (const Cube& s)
    - Implementation Syntax(.cpp) --> Cube & Cube::operator = (const Cube& s)

    -Assignment operator:
        -Similar to copy constructor: make LHS be the same value as RHS 
        -Different from copy constructor: clean out old values in LHS 

    -Copy Assignment Operator: 
        - Copies and object, AND destroys the object, unlike copy constructors and destructors which only do one 
        - private member function: clear_() --> clears of memory
                                    copy_(a) --> copy into LHS
*/

/* Inheritance & polymorphism
    - For inheritance, we will be doing extremely simple applications
    - Polymorphism is the idea that a single interface may take multiple types or that a single symbol may be different types 
        - Must use either a pointer or a reference to do this in C++
        - Shown in Rubik folder --> use "virtual" keyword -->1) look at type, 2) look for method (look for derived type (if virtual)) otherwise use method, 3)recures to base type --> go to 2

*/

//Rule of 3: Assignment operator, copy constructor, destructor --> must implement all 3 or none
//Rule of zero: Classes that declare custom destructors, copy/move constructors or copy/move assignment operators should deal exclusively with ownership
//              Other classes should NOT do these things

int main() {
    cs225::Cube c(5.0);      //declares c as a local variable of type cs225::Cube, and takes in a double for the constructor
    cout << "Volume: " << c.getVolume() <<endl;
    std::cout<< "Address storing 'c': " << &c << std::endl;
    
    cs225::Cube *ptr = &c;
    std::cout << "Addr. storing ptr: " << &ptr << std::endl;
    std::cout << "Contents of ptr: " << ptr << std::endl;
    
    return 0;
}