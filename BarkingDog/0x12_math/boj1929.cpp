#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    int num = b-a+1;

    int *arr = (int *)malloc(sizeof(int) * (b-a+1));
    for(int i = 0; i<num; i++){
        arr[i] = a+i;
    }

    for(int div = 2; div<=sqrt(b); div++){
        for(int i = 0; i<num; i++){
            if(arr[i] == div) continue;
            if(arr[i] % div == 0){
                arr[i] = -1;
            }
        }
    }

    int temp;


    for(int i = 0; i<num; i++){
        if(arr[i] == -1) continue;
        if(arr[i] == 1) continue;
        else{
            printf("%d\n", arr[i]);
        }
    }


    return 0;
}