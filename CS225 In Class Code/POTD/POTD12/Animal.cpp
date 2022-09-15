// Animal.cpp
#include <iostream>
#include "Animal.h"

Animal::Animal() {
    type_ = "cat";
    food_ = "fish";
}

Animal::Animal(string type, string food) {
    type_ = type;
    food_ = food;
}

void Animal::setType(string type) {
    type_ = type;
}

string Animal::getType() {
    return type_;
}

void Animal::setFood(string food) {
    food_ = food;
}

string Animal::getFood() {
    return food_;
}

string Animal::print() {
    string message = "I am a " + this->getType() + ".";
    return message;
}