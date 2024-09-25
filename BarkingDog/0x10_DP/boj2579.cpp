#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int *value = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        scanf("%d", &value[i]);
    }

    int **DP = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i<n; i++){
        DP[i] = (int *)malloc(sizeof(int) * 2);
        for(int j = 0; j<2; j++){
            DP[i][j] = 0;
        }
    }

    //DP의 초기값 설정
    DP[0][0] = 0;
    DP[0][1] = 0;
    
    DP[1][0] = 0;
    DP[1][1] = value[0]; //1층의 값
    DP[2][0] = value[1]; //2층의 값
    DP[2][1] = value[0] + value[1]; //1층의 값 + 2층의 값

    //3층부터 고려
    for(int i = 3; i<n; i++){

        //지금 층에 +2 해서 올라온 경우
        DP[i][0] = max(DP[i-2][0], DP[i-2][1]) + value[i-1];
        
        //지금 층에 +1 해서 올라온 경우
        DP[i][1] = DP[i-1][0] + value[i-1];

    }

    int result = max(DP[n-1][0], DP[n-1][1]);

    printf("%d", result);

    return 0;
}