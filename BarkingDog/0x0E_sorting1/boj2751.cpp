#include <stdio.h>
#include <stdlib.h>

int n;
int *arr;
int *temp;

//arr[st]~arr[mid], arr[mid]~arr[end] 는 정렬되어 있음
//두개의 sub arr을 merging
void merge(int st, int end){
    int mid = (st+end)/2;
    int left_index = st;
    int right_index = mid;
    
    for(int i = st; i<end; i++){
        if(left_index == mid){
            temp[i] = arr[right_index++];
        } else if (right_index == end){
            temp[i] = arr[left_index++];
        } else if (arr[left_index] <= arr[right_index]){
            temp[i] = arr[left_index++];
        } else {
            temp[i] = arr[right_index++];
        }
    }

    for(int i = st; i<end; i++){
        arr[i] = temp[i];
    }

}

void merge_sort(int st, int end){
    if(st+1 == end) return;
    int mid = (st+end)/2;
    merge_sort(st, mid);
    merge_sort(mid, end);
    merge(st, end);
}

int main(){

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    temp = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    merge_sort(0, n);

    //정렬 결과 출력
    for(int i = 0; i<n; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}