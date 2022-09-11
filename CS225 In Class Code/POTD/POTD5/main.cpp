// your code here
#include <iostream>
#include <string>
#include "Food.h"
#include "q5.h"
using std::string;
using std::cout;
using std::endl;

int main() { 
    Food * new_food = new Food("Steak", 12);
    cout<< "You have " << new_food->get_quantity() << " " << new_food->get_name() << "."<<endl;
    (increase_quantity(new_food));  
    cout<< "You have " << new_food->get_quantity() << " " << new_food->get_name() << "."<<endl;
}