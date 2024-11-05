#include <stdio.h>
#include <stdlib.h>

int n, m;
int *arr;
int *answer;

//answer[k]가 정해진 상황, answer[k+1]을 구하는 함수
void func(int k, int start){

    if(k == m){
        for(int i = 0; i<m; i++){
            printf("%d ", answer[i]);
        }
        printf("\n");
        return;
    }

    for(int i = start; i<n; i++){
        answer[k] = arr[i];
        func(k+1, i+1);
    }
}


int main(){
    scanf("%d %d", &n, &m);
    

    arr = (int *)malloc(sizeof(int) * n);
    answer = (int *)malloc(sizeof(int) * m);

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    //arr 배열 정렬하기
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    func(0, 0);

    return 0;
}