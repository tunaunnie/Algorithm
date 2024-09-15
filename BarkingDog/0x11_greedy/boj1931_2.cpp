#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int* a, const int* b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int main(){

    int n;
    scanf("%d", &n);

    int **table = (int **)malloc(sizeof(int *) * n);
        for(int i = 0; i<n; i++){
            table[i] = (int *)malloc(sizeof(int ) * 2);
        }

    for(int i = 0; i<n; i++){
        scanf("%d %d", &table[i][0], &table[i][1]);
    }

    ///////////////// 입력 받고 저장 ////////////////

    // 끝나는 시간 기준으로 정렬 
    
    sort(table, table+n, compare);

    int count = 1;
    int last_end_time = table[0][1];

    for(int i = 1; i<n; i++){
        if(table[i][0] >= last_end_time ){
            count++;
            last_end_time = table[i][1];
        }
    }

    printf("%d", count);

    return 0;
}