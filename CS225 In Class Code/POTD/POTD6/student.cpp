// Your code here! :)
#include <iostream>
#include "student.h"
using namespace potd;

Student::Student(){};

Student::Student(string name, int grade) {
    name_ = name;
    grade_ = grade;
}

void Student::set_name(string name) {
    name_ = name;
}

void Student::set_grade(int grade) {
    grade_ = grade;
}

string Student::get_name() {
    return name_;
}

int Student::get_grade() {
    return grade_;
}