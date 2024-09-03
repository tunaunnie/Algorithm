#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int num;
long **array;
int count = 1;



int recursion(int max_start, int temp){

    int max_start2 = -1;
    int flag = 0;

    for(int i = 0; i<num; i++){
        //받은 start보다 전에 끝나는 애들 중에
        if(array[i][1] <= max_start){

            //가장 start가 빠른 시간 찾음
            if(max_start2 <= array[i][0] && temp != i){
                max_start2 = array[i][0];
                temp = i;

                //하나라도 다음 회의가 있으면 flag = 1
                flag = 1;
            }
            
        }
    }

    if(flag == 0){
        return 0;
    }

    count++;

    return recursion(max_start2, temp);
}

int main(){

    scanf("%d", &num);
    array = (long **)malloc(sizeof(long *) * num);

    for(int i = 0; i<num; i++){
        array[i] = (long *)malloc(sizeof(long)* 2);
    }

    for(int i = 0; i<num; i++){
        for(int j = 0; j<2; j++){
            array[i][j] = 0;
        }
    }

    for(int i = 0; i<num; i++){
        scanf("%ld %ld", &array[i][0], &array[i][1]);
    }

    //종료 시간이 큰 순서대로 정렬하기
    for(int i = 0; i<num; i++){
        for(int j = 0; j<= i; j++){
            if(array[i][1] >= array[j][1]){
                int temp = array[i][1];
                array[i][1] = array[j][1];
                array[j][1] = temp;
            }
        }
    }

    for(int i = 0; i<num; i++){
        for(int j = 0; j<num; j++){
            if(i!=j && array[i][1] == array[j][1]){
                if(array[i][0] >= array[j][0]){
                    int temp = array[i][0];
                    array[i][0] = array[j][0];
                    array[j][0] = temp;
                }
            }
        }
    }
    


    //가장 start가 큰 회의의 시작점, 끝점 저장
    long max_start = -1;
    int temp;

    for(int i = 0; i<num; i++){
        if(max_start <= array[i][0]){
            max_start = array[i][0];
            temp = i;
        }
    }

    recursion(max_start, temp);

    printf("%d", count);


    return 0;
}

/*

array[i][2]

(시작 시간, 끝나는 시간)

array를 끝나는 시간 기준으로 정렬하기. 내림차순으로.

start 숫자가 제일 큰 애 골라

그 애의 start보다 finish가 작은 애들 중, 제일 큰 start 값 골라

그 애의 start 보다 finish가 작은 애들 중, 제일 큰 start 값 골라

...

그 애의 start보다 finish가 작은 애가 없으면 stop

*/