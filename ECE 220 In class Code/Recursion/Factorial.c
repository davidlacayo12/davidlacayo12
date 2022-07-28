#include <stdio.h>

int Factorial(int n);

int main(){

}

int Factorial(int n){
    if (n==1){
        return 1;
    }
    else
        return n*Factorial(n-1);
}