#include <stdio.h>
#include <stdlib.h>

int main(){

    int t;
    scanf("%d", &t);

    for(int i = 0; i<t; i++){

        int n;
        scanf("%d", &n);

        int *arr = (int *)malloc(sizeof(int) * n);
        for(int i = 0; i<n; i++){
            arr[i] = 0;
        }

        //1을 나타내는 방법은 1개
        arr[0] = 1;
        //2를 나타내는 방법은 2개
        arr[1] = 2;
        //3을 나아내는 방법은 4개
        arr[2] = 4;

        for(int i = 3; i<n; i++){
            arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
        }

        printf("%d\n", arr[n-1]);

    }


    return 0;
}