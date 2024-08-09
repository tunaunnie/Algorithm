#include <stdio.h>

int main(){
    int count;
    scanf("%d", &count);

    int arr[100];
    int arr2[100];

    for (int i = 0; i<count; i++){
        scanf("%d %d", &arr[i], &arr2[i]);
    }

    for (int i = 0; i<count; i++){
        printf("%d\n", arr[i]+arr2[i]);
    }

    return 0;
}