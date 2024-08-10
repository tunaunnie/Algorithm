#include <stdio.h>
#include <stdlib.h>

int main(){

    int arr[10];
    int div;
    int res[42]; //나머지는 0부터 41까지 존재
    int count = 0;

    //전부 개수 0개로 초기화
    for(int i = 0; i<42; i++){
        res[i] = 0;
    }

    for(int i = 0; i<10; i++){
        scanf("%d", &arr[i]);
        div = arr[i]%42;
        res[div]++;
    }

    //개수가 0이 아니면 count 늘리기
    for(int i = 0; i<42; i++){
        if(res[i] != 0) count++;
    }

    printf("%d", count);

    return 0;
}