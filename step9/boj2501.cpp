#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    // 0 ~ n-1번방에 1~n으로 나눈 나머지 저장
    int *mod = (int *)malloc(sizeof(int) * (n+1));
    mod[n] = '\0';

    for(int i = 1; i<=n; i++){
        mod[i-1] = n%i;
    }

    int count = 0;
    for(int i = 0; i<n; i++){
        if(mod[i] == 0){
            count++;
        }
    }

    if(count < k) {
        printf("0");
        return 0;
    }

    /*
    mod 배열이 쭉 초기화되어 있음. 0인 것도 있고, 0이 아닌 것도 있음..
    0이 아니면 건너뛰고, 0인 것들 중 k번째로 작은 수 찾기
    */

   int temp = 0;
    for(int i = 0; i<n; i++){

        if(mod[i] == 0){
            temp++;
        }

        if(temp == k){
            printf("%d", i+1);
            return 0;
        }

    }

    return 0;
}