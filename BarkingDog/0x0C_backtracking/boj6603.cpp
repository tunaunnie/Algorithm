#include <stdlib.h>
#include <stdio.h>

int n;
int *arr;
int answer[6];

//k개 정해진 상황. 지금 answer[k] 찾는 중.
void func(int k){

    if(k == 6){
        for(int i = 0; i<6; i++){
            printf("%d ", answer[i]);
        }
        printf("\n");
        return;
    } else if (k == 0){
        for(int i = 0; i<n; i++){
            answer[0] = arr[i];
            func(1);
        }
    } else {
        for(int i = 0; i<n; i++){
            if(arr[i] > answer[k-1]){
                answer[k] = arr[i];
                func(k+1);
            }
        }

    }    
}

int main(){

    scanf("%d", &n);

    while(n != 0){

        arr = (int *)malloc(sizeof(int) * n);
        for(int i = 0; i<n; i++){
            scanf("%d", &arr[i]);
        }

        //주어진 arr 배열에서 6개 고른 집합 전부 찾아 출력하는 함수
        func(0);
        printf("\n");

        //다음 테스트 케이스 수 받음
        scanf("%d", &n);
    }




    return 0;
}