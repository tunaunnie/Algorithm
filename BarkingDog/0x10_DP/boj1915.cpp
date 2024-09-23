#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int **board = (int **)malloc(sizeof(int *) * m);
    for(int i = 0; i<m; i++){
        board[i] = (int *)malloc(sizeof(int) * n);
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            board[i][j] = 0;
        }
    }

    for(int i = 0; i<m; i++){
        char *buffer = (char *)malloc(sizeof(char) * (n+1));
        scanf("%s", buffer);
        for(int j = 0; j<n; j++){
            board[i][j] = buffer[j] - '0';
        }
    }

    if( n == 1 || m == 1){
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 1){
                    printf("1");
                    return 0;
                }
            }
        }
        printf("0");
        return 0;
    }



    for(int i = 1; i<m; i++){
        for(int j = 1; j<n; j++){
            if(board[i][j] == 1){
                board[i][j] = min({board[i][j-1], board[i-1][j-1], board[i-1][j]}) + 1;
            }
        }
    }

    int max = 0;

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] > max){
                max = board[i][j];
            }
        }
    }

    printf("%d", max*max);


    return 0;
}