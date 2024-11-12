#include <stdio.h>
#include <stdlib.h>

int n, m;
int *arr;
int *answer;


//k개까지 채웠고, answer[k] 채우는 함수
void func(int k){

    if(k == m){
        for(int i = 0; i<m; i++){
            printf("%d ", answer[i]);
        }
        printf("\n");
        return;
    } else {
        for(int i = 0; i<n; i++){
            if(arr[i] >= answer[k-1]){
                answer[k] = arr[i];
                func(k+1);
            }
        }
    }

}


int main(){

    scanf("%d %d", &n, &m);
    arr = (int *)malloc(sizeof(int) * n);
    answer = (int *)malloc(sizeof(int) * m);

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for(int i = 0; i<n; i++){
        //answer = { 0 };
        answer[0] = arr[i];
        func(1);
    }



    return 0;
}