#include <stdio.h>
#include <stdlib.h>

int main(){

    int matrix[9][9];
    int max_row = 0;
    int max_column = 0;

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int max = matrix[0][0];

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(matrix[i][j] > max){
                max = matrix[i][j];
                max_row = i;
                max_column = j;
            }
        }
    }

    printf("%d\n%d %d", max, max_row+1, max_column+1);

    return 0;
}