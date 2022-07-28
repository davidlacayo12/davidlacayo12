#include <stdio.h>

#define ROW 2
#define COL 3

void print_2D(int a[][COL]);
void print_2D_ptr(int *a);

int main()
{
    int two[2][3] = {{1,2,3},{4,5,6}};

    print_2D(two);
    print_2D_ptr(&two[0][0]);
}


void print_2D(int a[][COL]){
    int i, j;
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            printf("%d ", a[i][j]);
            }
        printf("\n");
    }
    printf("\n");
}
void print_2D_ptr(int *a){
    int i, j;
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            printf("%d ", a[i*COL+ j]);
        }
        printf("\n");
    }
    printf("\n");
}