#include <stdio.h>
#include <math.h>

double Riemann(double a, double b, int n);
double f(double x);
int main(){
    double a,b;
    int n;
    printf("Enter a,b,n: ");
    scanf("%lf %lf %d", &a, &b, &n);
    printf("Integral value =  %lf\n", Riemann(a,b,n));
}

double f(double x){
    return cos(x); // any function
    //return x;
}
double Riemann(double a, double b, int n){
    double result;
    double dx= (b-a/n);
    double x,y;
    for(int i=0; i<n; i++){
        x = a + dx*i;
        y = f(x);
        result = result + dx*y;
    }

    return result;
}