#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);


    int *stair_scores = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        stair_scores[i] = 0;
    }
    for(int i = 0; i<n; i++){
        scanf("%d", &stair_scores[i]);
    }

    int **D = (int **)malloc(sizeof(int *)*n);
    for(int i = 0; i<n; i++){
        D[i] = (int *)malloc(sizeof(int) * 2);
        D[i][0] = 0;
        D[i][1] = 0; 
    }

    D[0][0] = stair_scores[0];
    D[0][1] = 0;
    //2층을 한번만에 올라간 경우
    D[1][0] = stair_scores[1];
    //2층을 두번만에 올라간 경우
    D[1][1] = stair_scores[0] + stair_scores[1];

    
    if(n == 1){
        printf("%d", stair_scores[0]);
        return 0;
    }

    if(n == 2){
        printf("%d", max(D[1][0], D[1][1]));
        return 0;
    }

    if(n > 2){
        for(int i = 2; i<n; i++){
            //1번만에 올라간 경우 : 2칸 전을 밟았다는 것
            D[i][0] = max(D[i-2][0], D[i-2][1]) + stair_scores[i];
            //2번만에 올라간 경우 : 1칸 전에 1번만에 올라온 경우였다는 것
            D[i][1] = D[i-1][0] + stair_scores[i];
        }
    }

    int max_score = max(D[n-1][0], D[n-1][1]);

    printf("%d", max_score);

    return 0;

}