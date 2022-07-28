#include <stdio.h>
#define SIZE 5

//helper functions
void bubbleSort(int array[], int n);
void insertSort(int array[], int n);
void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int *firstVal, int *secondVal);
void print1D(int array[], SIZE);

int main(){
    int array[SIZE] = {5, 1, 4, 2, 8};


}

void print_1D(int array[], SIZE ){
    for(int i =0; i < SIZE; i++){
        printf("%d", array[i]);
    }

}

void swap(int *firstVal, int *secondVal){       //Swap method 
    int temp;
    temp = *firstVal;
    *firstVal = *secondVal;
    *secondVal = temp; 

}



void bubbleSort(int array[], int n){
    int is_swap, i;
    do{
        is_swap = 0;
        for(i=0; i < n-1; i++){
            if(array[i] > array[i+1]){
                swap(&array[i], &array[i+1]); 
                is_swap = 1;
            }
        }
    }while(is_swap != 0);
}



void insertSort(int array[], int n){     //Insertion Sort

    int unsorted;                            // Index for unsorted list items
    int sorted;                              // Index for sorted items
    int unsortedItem;                       // Current item to be sorted
    // Loop from 1 thru n
    for(unsorted =1; unsorted < n; unsorted++){         // Loop from unsorted-1 thru 0
        unsortedItem = array[unsorted];
// if unsortedItem < current sorted item, shift the current item to the right
// stop if we hit a smaller element than unsortedItem
        sorted = unsorted-1;
        while((unsortedItem > array[sorted]) &&  (sorted >= 0)){
            array[sorted+1]= array[sorted];
            sorted--;
        }//finish doing right-shift for red item
    array[sorted+1] = unsortedItem;
}

}

void quickSort(int array[], int low, int high){
    //base case
    if(low >= high)
        return;
    //recursive case
    int pivot_index = partition(array,pivot_index-1,high);  //first half
    quickSort(array, pivot_index+1, high);                  //second half

}


int partition(int array[], int low, int high){
    /*for j from low to high-1
    if array[j] < pivot
        i = i + 1;
        swap array[i] and array[j]
    }
    swap array[i+1] and pivot
    return i+1 as the pivot index
    */

}


