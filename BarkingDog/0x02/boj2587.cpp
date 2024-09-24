#include <stdio.h>

int main(){

    int arr[5];
    int sum = 0;

    for(int i = 0; i<5; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("%d\n", sum/5);

    for(int i = 0; i<5; i++){
        for(int j = 0; j<=i; j++){
            if(arr[i] >= arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("%d", arr[2]);

    return 0;
}