#include <stdio.h>

void string_copy(char des[], char src[]);       //initializes string_copy with destination and source string arrays

int main(){
    //char buf[200];
    //buf = "ABC"; --> compile error
    //string_copy(buf,"ABC");
    char src[10] = "ABC";
    char des[10];

    string_copy(des, src);
    printf("%s\n", des);
}

void string_copy(char des[], char src[]){

    int i;
    while(src[i] != '\n'){          //as long as a character in the string is not null, the string will move from source to destination
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';

}