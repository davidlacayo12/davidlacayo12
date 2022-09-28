#include "potd.h"

// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end) {
    double total = 0;
    for(auto it = start; it != end; it++) {
        total += (*it);
    }
    return total;
}

vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end) {
    vector<double>::iterator maximum = start;

    for(auto it = start; it != end; it++) {
        if((*it) > *maximum) {maximum = it;}
    }
    return maximum;
}

void sort_vector(vector<double>::iterator start, vector<double>::iterator end) {
    for(auto it = start; it != end; it++) {
        auto max1 = max_iter(it, end);
        double max2 = *max1;
        *max1 = *it;
        *it = max2;

    }
}
