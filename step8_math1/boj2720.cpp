#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;
    scanf("%d", &num);

    int **answer;  
    
    // answer[num][4]
    answer = (int **)malloc(sizeof(int *)*num);
    for(int i = 0; i<num; i++){
        answer[i] = (int *)malloc(sizeof(int) *4);
    }

    for(int i = 0; i<num; i++){

        int x;
        scanf("%d", &x);

        printf("받은 값: %d\n", x);

        answer[i][0] = x/25;
        x %= 25;
        answer[i][1] = x/10;
        x %= 10;
        answer[i][2] = x/5;
        x %= 5;
        answer[i][3] = x/1;

    }

    for(int i = 0; i<num; i++){
        for(int j = 0; j<4; j++){
            if(j!=3)
                printf("%d ", answer[i][j]);
            else printf("%d", answer[i][j]);
        }
        printf("\n");
    }


    return 0;
}
