#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    if(n%2 ==0){
        printf("%d", (1+n)*(n/2));
    }else{
        printf("%d", (1+n)*(n/2) + (1+n)/2);
    }

    return 0;
}