#include <stdio.h>

int factorial(int n){

    int result = 1;
    for(int i = 1; i<=n; i++){
        result *= i;
    }

    return result;
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int result = factorial(n) / (factorial(n-k) * factorial(k));

    printf("%d", result);


    return 0;
}