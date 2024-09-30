#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i<n; i++){

        if(i == 0){
            printf("0 ");
            continue;
        }
        
        int j = i-1;
        int flag = 0;

        while(j >= 0){

            if(arr[i] > arr[j]){
                j--;
            } else { //arr[i] 보다 지금 보고 있는 arr[j]가 더 큼!! 수신 가능
                printf("%d ", j+1);
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            printf("0 ");
        }
    }



    return 0;
}