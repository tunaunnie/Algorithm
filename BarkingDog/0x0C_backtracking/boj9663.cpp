#include <stdio.h>
#include <stdlib.h>

int *check_1;
int *check_2;
int *check_3;

int n;
int count = 0;

//0번째 줄에서 놓을 위치 정하는 함수
void func(int k){

    if(k == n){
        count ++;
        return;
    }

    for(int i = 0; i<n; i++){
        if(check_1[i] == 0 && check_2[k-i+n-1] == 0 && check_3[k+i] == 0){
            check_1[i] = 1;
            check_2[k-i+n-1] = 1;
            check_3[k+i] = 1;
            func(k+1);
            check_1[i] = 0;
            check_2[k-i+n-1] = 0;
            check_3[k+i] = 0;
        }
    }

    return;
}


int main(){

    scanf("%d", &n);

    check_1 = (int *)malloc(sizeof(int) * n);
    check_2 = (int *)malloc(sizeof(int) * (2*n-1));
    check_3 = (int *)malloc(sizeof(int) * (2*n-1));

    for(int i = 0; i < n; i++) check_1[i] = 0;
    for(int i = 0; i < 2*n-1; i++) check_2[i] = 0;
    for(int i = 0; i < 2*n-1; i++) check_3[i] = 0;

    if (n != 1) {
        func(0);
    } else {
        printf("1");
        return 0;
    }

    printf("%d", count);
    

    return 0;
}