#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    //n개의 바구니 있고, 공도 1번부터 n번까지 있음
    int *arr = (int *)malloc(sizeof(int) * n);

    for(int i=0; i<n; i++){
        arr[i] = 0;
    }

    for(int a=0; a<m; a++){
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);

        for(int b=i; b<=j; b++){
            arr[b-1] = k;
        } 
    }

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}