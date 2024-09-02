#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;
    scanf("%d", &num);

    int *time = (int *)malloc(sizeof(int) * num);
    int *accum_time = (int *)malloc(sizeof(int)*num);

    for(int i = 0; i<num; i++){
        scanf("%d", &time[i]);
        accum_time[i] = 0;
    }

    //숫자가 작은 순서대로 정렬
    for(int i = 0; i<num; i++){
        for(int j = i+1; j<num; j++){
            if(time[i] > time[j]){
                int temp = time[i];
                time[i] = time[j];
                time[j] = temp;
            }
        }
    }

    // printf("정렬 후: \n");
    // for(int i = 0; i<num; i++){
    //     printf("%d ", time[i]);
    // }
    // printf("\n");

    int sum = 0;

    for(int i = 0; i<num; i++){
        for(int j = 0; j<=i; j++){
            accum_time[i] += time[j];
        }

        sum += accum_time[i];
    }

    printf("%d", sum);


    return 0;
}



/*

줄을 서는 사람이 5명

1, 2, 3, 4, 5

모든 경우의 수로 만들어보는 개수 : 5!

---
시간을 계산하는 법: 누적합을 다 더해야 함
1, 3, 6, 10, 15의 총합.

줄을 서는 순서에 따라서 각 사람의 누적합이 달라짐.
매번 순서를 바꿔야하나?

그냥 제일 적은 사람 순서대로 정렬하면 되나?


*/