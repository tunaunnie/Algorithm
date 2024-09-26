#include <stdio.h>

int main(){

    int height[9];
    int sum = 0;

    for(int i = 0; i<9; i++){
        scanf("%d", &height[i]);
        sum += height[i];
    }

    int index1, index2;

    for(int i = 0; i<=7; i++){
        for(int j = i+1; j<=8; j++){
            if(sum - height[i] - height[j] == 100){
                index1 = i;
                index2 = j;
            }
        }
    }

    int answer[7];
    int index = 0;
    
    for(int j = 0; j<9; j++){
        if(j==index1 || j==index2){
            continue;
        }
        answer[index++] = height[j];
    }

    for(int i = 0; i<7; i++){
        for(int j = i+1; j<7; j++){
            if(answer[i] > answer[j]){
                int temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }

    for(int i = 0; i<7; i++){
        printf("%d\n", answer[i]);
    }

    return 0;
}