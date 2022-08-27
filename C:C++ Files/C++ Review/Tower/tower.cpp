#include <iostream>
#include "tower.h"

using std::cout;
using std::endl;


/*Tower::Tower(const Tower & other) {
        cube_ = other.cube_;        //<-- class exists too late to create a reference variable
        ptr_ = other.ptr_;
        ref_ = other.ref_;          <-- will not compile because of reference, due to ref_ being a reference type 
}
*/

//correct orientation: using Constructor Initializer List
namespace cs225 {
    Tower::Tower(const Tower & other) : cube(other.cube_), ptr_(other.ptr_), ref_(other.ref_) { } 
    
}

/* Tower::Tower(const Tower & other) { 
    - Deep copy cube_:
        cube_ = other.cube_; --> make a new cube that is a copy 
    
    - Deep copy ptr_: 
        ptr_ = other.ptr_; <-- NOT DEEP COPY
        ptr_ = new Cube(*other.ptr_); <-- correct orientation-- new cube constructed by dereferencing the cube 
    
    - Deep copy ref_:
        ???? WTF?! --> deepy copy is the idea of an INDEPENDENT copy --> going into object and copying all of the core features  --> taken care of in ptr_ deep copy 
}

*/

