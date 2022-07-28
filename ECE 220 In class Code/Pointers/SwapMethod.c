#include <stdio.h>

void NewSwap(int *firstVal, int *secondVal);        //declaration of NewSwap method 

int main(){
        int valueA = 1;
        int valueB = 2;
        NewSwap(&valueA, &valueB);  //function call to NewSwap method using the addresses of valueA and valueB

        printf("Value A is %d\n", valueA);  //prints new A value
        printf("Value B is %d\n", valueB);  //prrints new B value 
    }
    void NewSwap(int *firstVal, int *secondVal)
    {
        int tempVal;

        tempVal = *firstVal;            //puts value of A into tempVal
        *firstVal = *secondVal;         //puts value of B into memory address of A
        *secondVal = tempVal;           //puts value of A into the address of B 
    }

    


