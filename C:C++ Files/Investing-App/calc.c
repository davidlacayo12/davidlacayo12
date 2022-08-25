//#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

//calculates the averages of two floats
double calculate_average(double a, double b){
    double temp=0.0;
    temp = ((a+b)/2);
    return temp;
}

//calculates sum of 1D array with the given length 
double calculate_sum_array(double arr[], int length){
    double sum=0;
    for(int i = 0; i < length; i++){
        sum= sum + (arr[i]);
    }
}

//calculates the sum of all of the columns per row-- return 1D array 
double calculate_sum_double_array(double arr[][], int row, int col){
    double temp[row];
    for(int i = 0; i< row; i++){
        for(int j = 0; j < col; j++){
            temp[i] = temp[i] + arr[i][j];
        }
    }
    return temp;
}


