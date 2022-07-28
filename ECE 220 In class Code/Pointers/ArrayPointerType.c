#include <stdio.h>

int main(){

    int word[10] = {1,2,3};
    int *cptr;
    cptr = word;            //points to word[0]

    printf("%p\n", cptr);
    printf("%p\n", word );
    printf("%p\n", &word[0]);
    
    printf("\n\n", *cptr);
    printf("%p\n", *word);
    printf("%p\n", word[0]);

}