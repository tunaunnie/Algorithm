#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    //배열 공간 할당
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for(int i = 0 ; i<n; i++){
        matrix[i] = (int *)malloc(sizeof(int) * m);
    }
    int **matrix2 = (int **)malloc(sizeof(int *) * n);
    for(int i = 0 ; i<n; i++){
        matrix2[i] = (int *)malloc(sizeof(int) * m);
    }
    int **sum = (int **)malloc(sizeof(int *) * n);
    for(int i = 0 ; i<n; i++){
        sum[i] = (int *)malloc(sizeof(int) * m);
    }

    //입력 받기
    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    //합 계산
    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            sum[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }

    //합 출력
    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
           printf("%d", sum[i][j]);
           if(j != m-1){printf(" ");}
        }
        printf("\n");
    }

    return 0;
}