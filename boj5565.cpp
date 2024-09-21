#include <stdio.h>

int main(){

    int sum;
    scanf("%d", &sum);

    for(int i = 0; i<9; i++){
        int a;
        scanf("%d", &a);

        sum-=a;
    }

    printf("%d", sum);




    return 0;
}