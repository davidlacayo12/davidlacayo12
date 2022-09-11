// Your code here
#pragma once 
#include <string>
using std::string;

class Food {
    public:
        Food();
        Food(string name, int quantity);
        string get_name();
        int get_quantity();
        void set_name(string name);
        void set_quantity(int quantity);
    private:
        string name_;
        int quantity_;
};