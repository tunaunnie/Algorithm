#include <stdio.h>
#include <stdlib.h>

int n;
int *arr;

void quick_sort(int start, int end){

    if(start+1 >= end) return;

    int pivot = start;
    int left = start;
    int right = end-1;

    while(true){

        while(left <= right && arr[left] <= arr[pivot]) left++;
        while(left <= right && arr[right] >= arr[pivot]) right--;
        if(left > right) break;

        int temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;
    }
    int temp = arr[start];
    arr[start] = arr[right];
    arr[right] = temp;

    quick_sort(start, right);
    quick_sort(right+1, end);
}

int main(){

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    quick_sort(0, n);

    for(int i = n-1; i>=0; i--){
        printf("%d\n", arr[i]);
    }

    return 0;
}