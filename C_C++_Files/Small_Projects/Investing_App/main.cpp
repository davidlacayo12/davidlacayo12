#include <iostream>
#include "Calc.h"
#include "Utils.h"


int main(){
    vector<int> v;

    for(size_t i = 0; i < 100; i++) {
        for(size_t j = 0; j < 100; j++) {
            v.push_back(i*j);
        }
    }

    int average = calc_1D_vector_average(v);
    cout << "The average value of the array is: " << average << "." << endl;

}