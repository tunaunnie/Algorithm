#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int *arr = (int *)malloc(sizeof(int) * n);
    int *arr2 = (int *)malloc(sizeof(int) * m);

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i<m; i++){
        scanf("%d", &arr2[i]);
    }

    int *answer = (int *)malloc(sizeof(int) * (n+m));

    int index = 0;
    int index2 = 0;
    int index3 = 0;

    //둘 다 끝까지 도달하기 전에는 계속 반복
    while(index3 < n+m){

        if(index == n){
            answer[index3++] = arr2[index2++];
        } else if (index2 == m){
            answer[index3++] = arr[index++];

        } else { //둘 다 아직 범위 내임.

            //둘 중 더 작은 값을 answer에 집어넣음음
            if(arr[index] < arr2[index2]){
                answer[index3++] = arr[index++];
            } else {
                answer[index3++] = arr2[index2++];
            }

        }

    }

    for(int i = 0; i<n+m; i++){
        printf("%d ", answer[i]);
    }


    return 0;
}