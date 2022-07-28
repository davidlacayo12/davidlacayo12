#include <stdio.h>
#include <math.h>


int main(){
    float a,b,c;    //coefficients
    float D;        //determinant
    float x1,x2;    //solution(s)
    //get equation coefficients 
    printf("Enter a,b,c: ");
    scanf("%f %f %f, &a,&b,&c");

    D = b*b - 4*a*c;

    if(D == 0){
        x1 = -b/(2*a);
        printf("x1 = %f\n", x1);
    }

    else if(D > 0){
        x1 = (-b+sqrt(D));
        x2 = (-b-sqrt(D));
        printf("x1 = %f\n x2 = %f\n", x1,x2);
    }

    else{
        printf("No real roots \n");
    }

}