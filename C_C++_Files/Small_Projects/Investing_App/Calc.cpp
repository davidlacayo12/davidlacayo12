#include <iostream>
#include "Calc.h"

int calc_average(int a, int b) {
    return (a+b)/2;
}

int calc_1D_vector_average(vector<int> v) {
    int sum = 0;
    size_t size = v.size();
    for(size_t index = 0; index < size; index++) {
        sum += v[index];
    }
    return sum / size;
}

int calc_2D_vector_average(vector<vector<int> > v) {
    int sum = 0;
    int elem = 0;
    for(size_t x = 0; x < v.size(); x++) {
        for(size_t y = 0; y < v[x].size(); y++) {
            sum += v[x][y];
            elem++;
        }
        elem++;
    }
    return sum / elem;
}