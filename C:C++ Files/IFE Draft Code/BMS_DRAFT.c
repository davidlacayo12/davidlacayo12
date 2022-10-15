#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define START 0
#define END 40
#define OV 4.1670           //voltage maximum per battery 
#define UV 2.750            //voltage minimum per battery, but not too worried about this 

void balance(double arr[], double ave); 
double calcAverage(double arr[]);
double calcMax(double arr[]);
double calcMin(double arr[]);
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
    for(int i = START; i < END; i++) {  //initializes array of cells to a start value 
        cells[i] = 2.5;
    }   
    //  for(int i = START; i < END; i++) {
    //     cells[i] = (rand() % 5) + 1;
    // } 

    while(1) {
        //Prints before balancing algorithm is active
        printf("Before balancing \n");
        printArr(cells);

        //calculate average of cells (Can be done in main method)
        double average = calcAverage(cells);
        double max = calcMax(cells);
        double min = calcMin(cells);

        //Balances the cell 
        if(max > OV) {
            exit(1);    //if a max voltage in our cells is over the overvault, stop balancing
            //Need to send messages before exit, and stop charging 
        }
        if(max < OV && min > UV) {
            balance(cells, average);
        }
      
        //Prints array after balancing algorithm has been implemented 
        printf("After Balancing: \n");
        printArr(cells);

        for(int i = START; i < END; i++) {  //increase cells 3 ways to simulate different voltage rates across cells 
            if(i % 2 == 0) {
                cells[i] += 0.1;
            }
            else if(i % 3 == 0) {
                cells[i] += 0.15;
            }
            else {
                cells[i] += 0.05;
            }
        }
        sleep(1);
    }
}

//helper function for calculating the average of our cells 
double calcAverage(double arr[]) {  
    double average = 0;
    double numCell = END - START;

    for(int cell = START; cell < END; cell++){
        average += arr[cell];
    }
    return (average / numCell);
}

//helper function for calculating the max of our cells 
double calcMax(double arr[]) {
    double max = 0;
    for (int cell = START; cell < END; cell++) {
        if(arr[cell] > max) {
            max = arr[cell];
        }
    }
    return max;
}

//helper function for calculating the max of our cells
double calcMin(double arr[]) {
    double min = arr[0];
    for(int cell = 1; cell < END; cell++) {
        if(arr[cell] < min) {
            min = arr[cell];
        }
    }
    return min;
}

//helper function that sets the value of each cell to the average
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