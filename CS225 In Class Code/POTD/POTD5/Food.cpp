// Your code here
#include <iostream>
#include "Food.h"

Food::Food() {};

Food::Food(string name, int quantity) {
    name_ = name;
    quantity_ = quantity;
}

std::string Food::get_name() {
            return name_;
        }

int Food::get_quantity() {
            return quantity_;
}

void Food::set_name(string name) {
    name_ = name;
}

void Food::set_quantity(int quantity) {
    quantity_ = quantity;
}