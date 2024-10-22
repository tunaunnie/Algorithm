#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int **cost = (int **)malloc(sizeof(int *) * 3);
    for(int i = 0; i<3; i++){
        cost[i] = (int *)malloc(sizeof(int) * n);
    }
    for(int i = 0; i<3; i++){
        for(int j = 0; j<n; j++){
            cost[i][j] = 0;
        }
    }

    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);

    cost[0][0] = r;
    cost[1][0] = g;
    cost[2][0] = b;

    for(int i = 1; i<n; i++){

        scanf("%d %d %d", &r, &g, &b);

        //이번 칸을 red로 칠하는 최소비용
        cost[0][i] = min(cost[1][i-1], cost[2][i-1]) + r;

        //이번 칸을 green으로 칠하는 최소비용
        cost[1][i] = min(cost[0][i-1], cost[2][i-1]) + g;

        //이번 칸을 blue로 칠하는 최소비용
        cost[2][i] = min(cost[0][i-1], cost[1][i-1]) + b;

    }

    int min_cost = min({cost[0][n-1], cost[1][n-1], cost[2][n-1]});

    printf("%d", min_cost);


    return 0;
}