#include <stdio.h>
#include <stdlib.h>

int pow(int base, int exp){
    int result = 1;
    for(int i = 0; i<exp; i++){
        result *= base;
    }
    return result;
}

int main(){

    int n;
    scanf("%d", &n);
    n -= 1;

    int index = 0;

    //0 ~ n-1까지 있음
    int *answer = (int *)malloc(sizeof(int) * n+1);
    answer[index++] = 4;

    //이전 답 초기화해두기..
    for(int i = 1; i<n; i++){

        //1)이전 사각형의 개수
        int temp1 = pow(2, 2*i);
        //2)추가되는 점의 개수
        int temp2 = 5 * temp1;
        //3)겹치는 점
        int temp3 = pow(2, i) * (pow(2, i) - 1) *2;
        //4)총추가
        int temp4 = temp2-temp3;
        //5) 답 계산하고 저장
        answer[i] = answer[i-1]+temp4;

        index = i++;
    }

    for(int i = 0; i<n; i++){
        printf("answer[%d]: %d \n", i, answer[i]);
    }

    //1)이전 사각형의 개수
    int temp1 = pow(2, 2*n);
    printf("temp1: %d ", temp1);
 
    //2)추가되는 점의 개수
    int temp2 = 5 * temp1;
    printf("temp2: %d ", temp2);
 
    //3)겹치는 점
    int temp3 = pow(2, n) * (pow(2, n) - 1) *2;
    printf("temp3: %d ", temp3);
 
    //4)총추가
    int temp4 = temp2-temp3;
    printf("temp4: %d ", temp4);
 
    //5) 답 계산하고 저장
    int result = answer[index-1]+temp4;
    printf("\n최종 답: %d + %d = %d ", answer[index-1], temp4, result);

    //printf("%d", answer[index]);

    return 0;
}


/*

** 이전 사각형의 개수: 2^2n
** 추가되는 점의 개수: 5 * (이전 사각형의 개수)
** 겹치는 점 : (2^n)*((2^n)-1)*2
** 총추가: 추가되는 점의 개수 - 겹치는 점

** 답 : 이전 답 + 총추가

** 이전 답: 하나씩 배열에 저장해둘까.


[0->1단계]
1) 추가되는 점: 5개
2) 겹치는 점: 0개
3) 총 추가: 5-0 = 5개
4) 답: 원래점+총추가 = 9

[1단계->2단계]  (n==1)
추가되는 점: 5*4개 (5*이전 사각형 개수)
겹치는 점: 4개 (내부의 변 개수만큼 겹침..)
총 추가: 20-4 = 16개
답: 원래점+총추가 = 9+16=25

2단계->3단계 (n==2)
추가되는 점: 5*16개 (5*이전 사각형 개수)
겹치는 점: 24개 (내부의 변 개수)
총추가: 80-24=56개
답: 원래점+총추가 = 16+56 = 72개



*/