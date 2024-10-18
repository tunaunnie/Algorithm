#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(){

    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int *press = (int *)malloc(sizeof(int) * f);
    for(int i = 0; i<f; i++){
        press[i] = -1;
    }

    press[s-1] = 0;

    queue<int> q;
    q.push(s);

    int now_floor;
    int upstair, downstair;

    while(!q.empty()){

        now_floor = q.front();
        q.pop();

        if(now_floor == g){
            printf("%d", press[now_floor-1]);
            return 0;
        }

        upstair = now_floor + u;
        downstair = now_floor - d;

        //범위 내에 맞으면
        if(upstair <= f && press[upstair-1] == -1){
            //printf("오 위로 갑니다: %d\n", upstair);
            press[upstair-1] = press[now_floor-1] + 1;
            q.push(upstair);
        }

        if(downstair >= 0 && press[downstair-1] == -1){
            //printf("오 아래로 갑니다: %d\n", downstair);
            press[downstair-1] = press[now_floor-1] + 1;
            q.push(downstair);
        }

    }

    printf("use the stairs");
    
    return 0;
}