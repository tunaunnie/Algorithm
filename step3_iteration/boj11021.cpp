#include <stdio.h>

int main(){

    int count;
    scanf("%d", &count);

    int arr[500];

    for(int i=0; i<count; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[i] = a+b;
    }

    for(int i=1; i<=count; i++){
        printf("Case #%d: %d\n", i, arr[i-1]);
    }

    return 0;
}