#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;
    scanf("%d", &num);

    int *arr;
    arr = (int *)malloc(sizeof(int) * num);

    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for(int i=0; i<num; i++){
        if(arr[i] > max) max=arr[i];
        if(arr[i] < min) min=arr[i];
    }

    printf("%d %d", min, max);

    free(arr);

    return 0;
}