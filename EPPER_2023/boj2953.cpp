#include <stdio.h>

int main(){

    int a, b, c, d;
    int score[5] = {0};

    for(int i = 0; i<5; i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        score[i] = score[i] + a + b + c + d;
    }

    int max = 0;
    int answer;

    for(int i = 0; i<5; i++){
        if(max < score[i]){
            answer = i;
            max = score[i];
        }
    }

    for(int i = 0; i<5; i++){
        if(max == score[i]){
            if(i != answer){
                return 0;
            }
        }
    }

    printf("%d %d", answer+1, max);


    return 0;
}