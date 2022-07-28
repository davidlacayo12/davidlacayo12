#include <stdio.h>


// Utility function to check if a queen can be placed on board[row][col]
int isSafe(int board[N][N], int row, int col);

int Solve(int board[N][N], int row){
    int j;//index for column
    if(row == N)
        return true;
    else{
        for(j=0;j<N;j++){
            if(isSafe(board, row, j) == true){
                board[row][j] = 1;
            // increment row to place the next queen
                if(Solve(board, row+1)== true)
                    return true;
                else
                    board[row][j] = 0; //remove the queen
            }
        }
        return false;
    }
}