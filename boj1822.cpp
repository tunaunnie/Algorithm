#include <stdio.h>
#include <stdlib.h>

//배열 B에 특정 원소가 있는지 탐색
//배열 B는 순서대로 정렬되어 있음
int find(int *arr, int size, int num){

    int low = 0; 
    int high = size -1;

    while (low <= high){
        int mid = (low + high) / 2;

        if(num == arr[mid]) return 1;

        if(num < arr[mid]){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    //없으면 0 반환
    return 0;
}

// 비교 함수 for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int main(){

    int num1, num2;
    scanf("%d %d", &num1, &num2);

    int *setA = (int *)malloc(sizeof(int) * num1);
    int *setB = (int *)malloc(sizeof(int) * num2);
    int *answers;

    //집합 A 원소 입력 받고 저장
    for(int i = 0; i<num1; i++){
        scanf("%d", &setA[i]);
    }

    //집합 B 원소 입력 받고 저장
    for(int i = 0; i<num2; i++){
        scanf("%d", &setB[i]);
    }

    // 배열 A, B를 퀵 정렬하기
    qsort(setA, num1, sizeof(int), compare);
    qsort(setB, num2, sizeof(int), compare);
    

    answers = (int *)malloc(sizeof(int) * num1);

    int pos = 0;

    //A를 순회하며, B에 없는 원소들만 answers에 저장
    //B를 미리 정렬했으므로 이분탐색 사용
    for(int i = 0; i<num1; i++){
        int exist = find(setB, num2, setA[i]);
        if(exist == 0){
            answers[pos++] = setA[i];
        }
    }

    //빠져나온 상태의 pos는 answer 배열의 원소 개수 가지고 있음

    if(pos == 0){
        printf("0\n");
        return 0;
    }

    printf("%d\n", pos);
    for(int i = 0; i<pos; i++){
        printf("%d", answers[i]);
        if(i != pos-1){printf(" ");}
    }

    free(setA);
    free(setB);
    free(answers);

    return 0;
}