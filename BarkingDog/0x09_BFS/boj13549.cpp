#include <stdio.h>
#include <stdlib.h>
#include <deque>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int take_time[100001]; //각 점까지 가는 데 걸리는 시간을 쓰기
    for(int i = 0; i<100001; i++){
        take_time[i] = -1;
    }
    take_time[n] = 0; //수빈이가 현재 있는 점은 0초 걸림.

    deque<int> dq;
    dq.push_front(n);

    int new_point;
    int now_point;

    while(!dq.empty()){

        now_point = dq.front();
        dq.pop_front();

        if(now_point == k){
            printf("%d", take_time[now_point]);
            return 0;
        }

        int dx[3] = {now_point *2, now_point-1, now_point+1};
        for(int i = 0; i<3; i++){

            new_point = dx[i];
            if(0 <= new_point && new_point < 100001 && take_time[new_point] == -1){
                take_time[new_point] = take_time[now_point] + 1;

                if(i == 0){
                    take_time[new_point] = take_time[now_point];
                    dq.push_front(new_point);
                } else {
                    take_time[new_point] = take_time[now_point] + 1;
                    dq.push_back(new_point);
                }
            }

        }

    }

    return 0;
}