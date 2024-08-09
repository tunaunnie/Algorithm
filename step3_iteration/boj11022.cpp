#include <stdio.h>

int main(){

    int count;
    scanf("%d", &count);

    int a[500];
    int b[500];
    int arr[500];

    for(int i=0; i<count; i++){
        scanf("%d %d", &a[i], &b[i]);
        arr[i] = a[i]+b[i];
    }

    for(int i=0; i<count; i++){
        printf("Case #%d: %d + %d = %d\n", i+1, a[i], b[i], arr[i]);
    }

    return 0;
}