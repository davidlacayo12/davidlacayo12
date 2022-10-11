#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define START 0
#define END 40
#define OV 4.1670           //voltage maximum per battery 
#define UV 2.750            //voltage minimum per battery, but not too worried about this 

void balance(double arr[], double ave); 
double calcAverage(double arr[]);
void printArr(double arr[]);

/*
    Rough implementation of what our algorithm will look like -> 2 things need to be noted: 
        1) If a cell's voltage is lower than the average, discharge will have to be decreased in order to balance "up" 
        2) if a cell's voltage is higher than the average, discharge will have to be increased in order to balance "down" 

    Next: Cell balancing set-up using by-pass FETs, is a hardware alternative, or "extra feature" that we could possibly work on
        to reinfornce the software side of things. With battery management systems, you can honestly never be too safe. Apparantly "meltdown"
        is when a battery cell sits at 4.35V, which should be avoided at all costs, and should be included in the balancing algorithm 

        TI Lists as following at the website: https://www.ti.com/download/trng/docs/seminar/Topic%202%20-%20Battery%20Cell%20Balancing%20-%20What%20to%20Balance%20and%20How.pdf

*/


int main() {

    double cells[END-START];
    /*Use to stop while loop*/    
    while(1) {
        //For loop stores random numbers in our array 
        for(int i = START; i < END; i++) {
            cells[i] = (rand() % 10) + 1;
        } 

        //Prints before balancing algorithm is active
        printf("Before balancing \n");
        printArr(cells);

        //calculate average of cells (Can be done in main method)
        double average = calcAverage(cells);
        //Balances the cell 
        balance(cells, average);

        //Prints array after balancing algorithm has been implemented 
        printf("After Balancing: \n");
        printArr(cells);

    }
    

}

double calcAverage(double arr[]) {
    double average = 0;
    double numCell = END - START;

    for(int cell = START; cell < END; cell++){
        average += arr[cell];
    }
    return (average / numCell);
}

void balance(double arr[], double average) {
    for(int cell = START; cell < END; cell++) {
        arr[cell] = average;
    }
}

void printArr(double arr[]) {
    for(int cell = START; cell < END; cell++) {
        printf("%lf ", arr[cell]);
    }
    printf("\n");
}