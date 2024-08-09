#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    for (int i=1; i<=n; i++){ //i는 1, 2, 3... n까지
        for (int j = 1; j<=n-i; j++){       //j는 n-1, n-2, n-3 .
            printf(" ");
        }
        for (int j = 1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}


/*

n줄까지

1) (n-1)만큼 공백, 1만큼 별
2) (n-2)만큼 공백, 2만큼 별

...

마지막은 n만큼 별


*/