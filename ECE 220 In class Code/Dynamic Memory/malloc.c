#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 10;
    int *ptr;
    ptr = &x;
    printf("%d\n", *ptr);

    ptr = (int*) malloc(sizeof(int));

    *ptr = 5;
    printf("%d\n", *ptr);

    int *ptr2 = (int*) malloc(sizeof(int));

    free(ptr);
    ptr = ptr2;

    free(ptr2);
  
}