#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;
    scanf("%d", &num);

    int *arr = (int *)malloc(sizeof(int) * num);
    int check[1000001] = {0};

    for(int i = 0; i<num; i++){
        scanf("%d", &arr[i]);
        check[arr[i]-1] = 1;
    }

    int sum;
    scanf("%d", &sum);

    int count = 0;
    for(int i = 0; i<num; i++){
        int goal = sum-arr[i];
        if(goal <1 || goal > 1000000) continue;
        if(check[goal-1] == 1) {
            count++;
        }
    }

    printf("%d", count/2);


    return 0;
}