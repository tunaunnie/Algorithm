#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int *price = (int *)malloc(sizeof(int) * n);

    //0부터 n-1까지 있음. price[n-1]이 가장 비싼 가격.
    for(int i = 0; i<n; i++){
        scanf("%d", &price[i]);
    }

    int count = 0;
    int temp = k;

    for(int i = n-1; i>=0; i--){
        if (temp == 0) break;

        count += (temp / price[i]);
        temp %= price[i];
    }

    printf("%d", count);


    return 0;
}


/*

k원 만들기.

일단 제일 비싼 가격으로 나눠.
나눠서 나온 몫은 += count
남은 나머지를 넘겨

두번째로 비싼 가격으로 나눠.
나눠서 나온 몫을 += count
남은 나머지를 넘겨

.. 1로 나누면 끝

*/