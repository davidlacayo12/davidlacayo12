// Animal.h
#pragma once
#include <string>
using std::string;

class Animal {
    public:
        Animal();
        Animal(string type, string food);
        void setType(string type);
        string getType();
        void setFood(string food);
        string getFood();
        string print();
    private:
        string type_;
        string food_;

};