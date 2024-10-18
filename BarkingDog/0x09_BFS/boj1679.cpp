#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    if(n == k){
        printf("0");
        return 0;
    }

    int take_time[100001];
    for(int i = 0; i<100001; i++){
        take_time[i] = -1;
    }

    //최초에 수빈이가 있던 자리
    take_time[n] = 0;

    queue<int> q;
    q.push(n);

    int now_point, new_point;
    
    while(!q.empty()){

        now_point = q.front();
        q.pop();

        int dx[3] = {1, -1, now_point};
        for(int i = 0; i<3; i++){

            //갈 수 있는 점 후보
            new_point = now_point + dx[i];

            //그 점 후보가 범위에 맞고, 아직 간 적도 없으면
            if( 0 <= new_point && new_point < 100001 && take_time[new_point] == -1){

                take_time[new_point] = take_time[now_point] + 1;
                //printf("%d 점까지 가는 데 %d시간 걸리네요\n", new_point, take_time[new_point]);

                if(new_point == k){
                    printf("%d", take_time[new_point]);
                    return 0;
                }

                q.push(new_point);

            }

        }    
    }

    return 0;
}