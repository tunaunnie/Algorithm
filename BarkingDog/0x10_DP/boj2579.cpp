#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int *value = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &value[i]);
    }

    int **DP = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++){
        DP[i] = (int *)malloc(sizeof(int) * 2);
        for(int j = 0; j < 2; j++){
            DP[i][j] = 0;
        }
    }

    // 1층에 2칸 넘어왔을리는 없고, 1칸 건너온 경우
    DP[0][0] = 0;
    DP[0][1] = value[0];

    if (n > 1) {
        //2층에 2칸 뛰어넘어온 경우
        DP[1][0] = value[1];
        
        //2층에 1칸, 1칸 넘어온 경우
        DP[1][1] = value[0] + value[1];
    }

    // 3층부터 고려
    for(int i = 2; i < n; i++){

        // 지금 층에 +2 해서 올라온 경우
        DP[i][0] = max(DP[i-2][0], DP[i-2][1]) + value[i];

        // 지금 층에 +1 해서 올라온 경우
        DP[i][1] = DP[i-1][0] + value[i];
    }

    int result = max(DP[n-1][0], DP[n-1][1]);

    printf("%d", result);

    return 0;
}
