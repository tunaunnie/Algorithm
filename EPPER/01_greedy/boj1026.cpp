#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i<n; i++){
        a[i] = 0;
        b[i] = 0;
    }

    for(int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i<n; i++){
        scanf("%d", &b[i]);
    }

    //b정렬을 오름차순으로 정렬
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            if(b[i] > b[j]){
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }


    //a정렬을 내림차순으로 정렬
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            if(a[i] < a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int sum = 0;

    for(int i = 0; i<n; i++){
        sum += a[i]*b[i];
    }

    printf("%d", sum);

    free(a);
    free(b);

    return 0;
}


/*

b정렬을 작은 순서대로 정렬시키기
a 정렬을 큰 순서대로 정렬시키기

곱한 값 출력


*/