// Your code here! :)
#include <iostream>
#include <string>
#include "student.h"
#include "q6.h"
using std::cout;
using std::endl;


int main() {
    potd::Student * student1 = new potd::Student("David", 11);
    cout << student1->get_name() << " is in grade " << student1->get_grade() << endl;
    graduate(*student1);
    cout << student1->get_name() << " is in grade " << student1->get_grade() << endl;
    delete student1;
}