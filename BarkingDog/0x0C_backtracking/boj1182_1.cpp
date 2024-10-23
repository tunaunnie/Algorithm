#include <stdio.h>
#include <stdlib.h>

int n, s;
int *arr;
int count = 0;

//index는 내가 arr에서 "지금" 보고 있는 원소.
void dfs(int index, int current_sum){

    if(index == n){
        return;
    }

    //현재 보고 있는 원소까지 다 더했을때 답이 되면
    //먼저 카운트해줌
    if(current_sum + arr[index] == s){
        count++;
    }

    dfs(index+1, current_sum + arr[index]);
    dfs(index+1, current_sum);
}



int main(){

    scanf("%d %d", &n, &s);

    arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    dfs(0, 0);

    printf("%d", count);

    return 0;
}