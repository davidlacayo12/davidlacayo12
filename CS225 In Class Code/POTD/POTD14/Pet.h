// Pet.h
#pragma once 
#include <string>
#include "Animal.h"
using std::string;


class Pet : public Animal {
    public:
        Pet();
        Pet(string animal, string food, string name, string ownerName);
        string getFood();
        string getName();
        string getOwnerName();
        void setFood(string food);
        void setName(string name);
        void setOwnerName(string ownerName);
        string print();

    private:
        string name_;
        string owner_name_;
};