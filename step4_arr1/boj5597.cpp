#include <stdio.h>
#include <stdlib.h>

int main(){

    int arr[28];
    int notexist[2];
    int index = 0;
    int flag;

    for(int i=0; i<28; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i<=30; i++){
        flag = 0;
        for(int j = 0; j<28; j++){
            if(i == arr[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) notexist[index++] = i;
    }

    if(notexist[0] > notexist[1]){
        int temp = notexist[0];
        notexist[0] = notexist[1];
        notexist[1] = temp;
    }

    printf("%d\n%d", notexist[0], notexist[1]);

    return 0;
}