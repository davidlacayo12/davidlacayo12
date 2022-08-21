#include <iostream> 
#include <limits>
#include <cmath>
using namespace std;

int switchtutorial(int input);

//setw() allows you to create rows and columns in user input and output   left and right at end of output line justifies content to the left or right 
//std::numeric_limits<T>::min() / max() / lowest() compute mins, max and other limits that are representable from a certain data type 
int main(){
    int a;
    int b;
    int max = (a > b) ? a:b;    //ternary expression --> result = (condition) ? option1:option2 --> if a > b, then a --> otherwise b 
    int COUNT = 10;
    int i = 0;
    do{
        cout << i <<" I love C++" << endl;
        i++;
    }while(i < COUNT);

}

int switchtutorial(int input) {
    switch(input){
        case 1: {
            cout << "1"<< endl;
        }
        break;

        case 2: {
            cout << "2" <<endl;
        }
        break;

        case 3: {
            cout << "3" <<endl;
        }
        break;
    }
    return 0;
}