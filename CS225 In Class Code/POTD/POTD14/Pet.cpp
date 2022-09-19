// Pet.cpp
#include <iostream> 
#include "Pet.h"
#include "Animal.h"

Pet::Pet(){
    name_ = "Fluffy";
    owner_name_ = "Cinda";

}

Pet::Pet(string animal, string food, string name, string ownerName){
    setType(animal);
    food_ = food;
    name_ = name;
    owner_name_ = ownerName;
}

string Pet::getFood(){
    return food_;
}

string Pet::getName(){
    return name_;
}

string Pet::getOwnerName(){
    return owner_name_;
}

void Pet::setFood(string food){
    food_ = food;
}

void Pet::setName(string name){
    name_ = name;
}

void Pet::setOwnerName(string ownerName){
    owner_name_ = ownerName;
}

string Pet::print() {
    return ("My name is " + getName());
}