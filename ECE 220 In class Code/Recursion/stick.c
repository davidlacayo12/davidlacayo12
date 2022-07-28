#include <stdio.h>
#define N 10
#define M 3

int solve(int solution[N], int idx, int total);

const int set[M] = {3,7,10};
//solution[N]: stores the solution
//idx: index for the solution matrix
//total: remaining length
int main(){
    int solution[N] = {0};
    int total, i;

    printf("Enter total length: ");
    scanf("%d", &total);

    if(solve(solution, 0, total)){
        printf("A solution found:\n");
        for(i=0;i<N;i++)
            printf("%d ", solution[i]);
    }
    else
        printf("No solution exists.\n");
}

int solve(int solution[N], int idx, int total){
    if((total == 0) && (idx <= 10)){    //base case 
        return 1;
    }
    else{               //recursive case 
        for(int j=0; j < M; j++){
            if( total - set[j] >= 0){       //safe move
                solution[idx] = set[j]; //make decision
                if (solve(solution, (idx+1) ,(total - set[j])) == 1)    //recursive call using newly calculated total and next index 
                    return 1;
                else    
                    solution[idx] = 0;
            }
        }
        return 0;
    }

}