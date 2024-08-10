#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;
    scanf("%d", &num);

    int *arr;
    arr =  (int *)malloc(sizeof(int) * num);

    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }

    int find;
    scanf("%d", &find);
    int count=0;

    for(int i=0; i<num; i++){
        if(arr[i] == find) count++;
    }

    printf("%d", count);

    free(arr);

    return 0;
}