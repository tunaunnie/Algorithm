#include <stdio.h>
#include <algorithm>

int main(){

    int num;
    scanf("%d", &num);

    int *array = (int *)malloc(sizeof(int)*num);

    for(int i = 0; i<num; i++){
        scanf("%d", &array[i]);
    }

    for(int i = 0; i<num; i++){
        for(int j = 0; j<num-i-1; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for(int i = 0; i<num; i++){
        printf("%d\n", array[i]);
    }

    return 0;
}