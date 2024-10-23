#include <stdio.h>
#include <stdlib.h>

int n, s;

int *arr;
int *visited;
int *subset;

int sum = 0;
int count = 0;


//k번째 원소까지 정해진 상태에서, subset[k] 번째 원소를 정하는 애.
//m개가 subset의 최대 길이
void func(int k, int m){
    
    if(k == m){
        for(int i = 0; i<m; i++){
            sum += subset[i];
        }
        if(sum == s){
            count++;
        }
        return;
    }

    //아직 안 갔으면 그걸 k번째 원소로 정하고 다음 칸 부르기
    for(int i = 0; i<n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            subset[k] = arr[i]; //지금 만들고 있는 subset에 저장
            func(k+1, m);  //그리고 다음 칸 채우러 가기
            visited[i] = 0; 
        }
    }
}

int main(){

    scanf("%d %d", &n, &s);

    //n개의 원소를 가진 배열 arr
    arr = (int *)malloc(sizeof(int) * n);
    visited = (int *)malloc(sizeof(int) * n);


    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
   

    //1개부터 n개까지의 크기를 가진 모든 부분수열 만들어보기
    //각 부분수열의 합을 계산하고, 그게 s와 같으면 1씩 추가
    for(int i = 0; i<n; i++){

        //방문기록 초기화하기
        for(int i = 0; i<n; i++){
            visited[i] = 0;
        }

        //subset에 길이 할당하기
        subset = (int *)malloc(sizeof(int) * (i+1));

        //0개 정해진 상태로 부분집합 구하기 시작
        //부분집합의 크기는 1, 2, 3, 4, ... n까지 구함
        func(0, i+1);

    }

    printf("%d", count);

    return 0;
}