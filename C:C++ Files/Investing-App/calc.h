#include <iostream>
#include <string.h>

class Company{
    private: 
        char name[30];
        double stock_value;

    public:
        Company(){};    //Default constructor 
        char[] get_name(){return name;}
        void set_name(char[] new_name){name = new_name;}
        double get_stock_value(){return stock_value;}
        void set_stock_value(double value){stock_value = value;}
}

double calculate_average(double a, double b);
double calculate_sum_array(double arr[], int length);
double calculate_sum_double_array(double arr[][], int row, int col);