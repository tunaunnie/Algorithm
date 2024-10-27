#include <stdio.h>
#include <stdlib.h>

int n, m;
int *arr;
int *answer;
int *visited;


//k를 '현재 정해진 원소의 개수' 라고 생각하면 편함.
//arr[k-1]이 정해진 상태에서, arr[k]를 정하는 함수.
void func(int k){

    if(k == m){
        //다 정해진 answer 배열 출력하고
        for(int i = 0; i<m; i++){
            printf("%d ", answer[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i<n; i++){

        if(visited[i] == 1) continue;

        answer[k] = arr[i];
        visited[i] = 1;

        func(k+1);
        visited[i] = 0;

    }
}

int main(){
    scanf("%d %d", &n, &m);
    
    answer = (int *)malloc(sizeof(int) * m);
    visited = (int *)malloc(sizeof(int) * n);
    
    //n개의 숫자 입력 받음.
    arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
        visited[i] = 0;
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

    //arr 배열에 들은 n개의 숫자 중, m개를 중복 없이 골라야 함.
    func(0);

    return 0;
}