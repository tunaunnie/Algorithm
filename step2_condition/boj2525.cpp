#include <stdio.h>

int main(){

    int hour, min, need;
    scanf("%d %d", &hour, &min);
    scanf("%d", &need);

    if(min+need < 60){
        printf("%d %d", hour, min+need);
    } else {
        //두 분의 합이 60을 넘어감
        if( hour + (min+need)/60 > 23){
            printf("%d %d", hour+(min+need)/60 - 24, (min+need)%60);
        } else {
            printf("%d %d", hour+(min+need)/60, (min+need)%60);
        }
    }

    return 0;
}

// 1) 두 분의 합이 60이 안 넘어갈 때: 그냥 계산
// 2) 두 분의 합이 60이 넘어갈 때
    //60으로 나눈 몫만큼 시간에 더하고, 60으로 나눈 나머지가 분이 됨

    //2-1) 몫을 시간에 더했는데 24 이상이 되면? -24해주기
    //2-2) 나머지를 분에 더했는데 60 이상이 되면? %60해주기

    //근데 만약 60으로 나눈 몫만큼 시간에 더했는데 24 이상이 되면 zero로 돌리기