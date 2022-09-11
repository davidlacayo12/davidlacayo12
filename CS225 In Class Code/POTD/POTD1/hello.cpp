/* Your code here! */
#include <iostream>
#include <string>
#include "hello.h"

std::string hello() {
    int age = 19;
    std::string name = "David";
    std::string greeting = "Hello world! My name is " + name + " and I am " + std::to_string(age) + " years old.";
   return greeting;
}