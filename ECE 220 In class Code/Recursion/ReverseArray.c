#include <stdio.h>
#define SIZE 5 

void array_reverse(int array[], int n);         //initializes array_reverse and print_array

void print_array(int array[], int n);

int main(){
    int arr[SIZE] = {1,2,3,4,5};

    print_array(arr, SIZE); 
}
//input 1 2 3 4 5
//output 5 4 3 2 1 

void array_reverse(int array[], int n){
    int i;
    int temp;

    for(i = 0; i < n/2; i++){
        temp = array[i];
        array[i] = array[n-1-i];            //basic algorithm for swapping array values 
        array[n-1-i] = temp;
    }

}

void print_array(int array[], int n){
    int i;

}