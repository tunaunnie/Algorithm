#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        arr[i] = 0;
    }

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            if(arr[i] <= arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int result = 0;

    for(int i = 0; i<n; i++){
        result += arr[i] * (n-i);    
    }

    printf("%d", result);


    return 0;
}


