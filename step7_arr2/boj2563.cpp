#include <stdio.h>

int main(){

    int num;
    scanf("%d", &num);

    int paper[100][100];
    //초기화
    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            paper[i][j] = 0;
        }
    }

    for(int i = 0; i<num; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        for(int j = x; j<x+10; j++){
            for (int k = y; k<y+10; k++){
                if(paper[j][k] == 0){
                    paper[j][k] = 1;
                }
            }
        } 
    }

    int count = 0;

    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            if(paper[i][j] == 1){
                count += 1;
            }
        }
    }

    printf("%d", count);

    return 0;
}