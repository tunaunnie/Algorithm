#include <stdio.h>
#include <stdlib.h>

int main(){

    int arr[9];
    int max=0;
    int index = 0;

    for(int i=0; i<9; i++){
        scanf("%d", &arr[i]);
    }

    max = arr[0];

    for(int i=0; i<9; i++){
        if(arr[i] > max) {
            max =  arr[i];
            index = i;
        }
    }

    printf("%d\n%d", max, index+1);

    return 0;
}