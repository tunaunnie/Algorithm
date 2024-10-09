#include <stdio.h>
#include <stdlib.h>
#include <iostream> //utility 포함
#include <queue>
#include <tuple>

using namespace std;

int main(){

    int m, n;
    scanf("%d %d", &m, &n);

    int **board = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i<n; i++){
        board[i] = (int *)malloc(sizeof(int) * m);
        for(int j = 0; j<m; j++){
            board[i][j] = -1;
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%d", &board[i][j]);
        }
    }

    // //입력 확인용 로그
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         printf("%d", board[i][j]);
    //     }
    //     printf("\n");
    // }

    queue<tuple<int, int, int>> q;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int last_day;

    //돌아다니면서 초기에 익은 토마토를 모두 큐에 집어넣음
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(board[i][j] == 1){
                q.push(make_tuple(i, j, 0)); //day 0으로 설정
            }
        }
    }

    while(!q.empty()){
        int now_x = get<0>(q.front());
        int now_y = get<1>(q.front());
        int now_day = get<2>(q.front());
        last_day = now_day;
        q.pop();

        //상하좌우 확인
        for(int i = 0; i<4; i++){
            int new_x = now_x + dx[i];
            int new_y = now_y + dy[i];

            //상하좌우 범위 검사 가능하고
            if(0<=new_x && new_x <n && 0<=new_y && new_y <m){

                //익지 않은 토마토이면
                if(board[new_x][new_y] == 0){
                    //토마토 익고
                    board[new_x][new_y] = 1;
                    //지금 익은 토마토를 queue에 push
                    q.push(make_tuple(new_x, new_y, now_day+1));
                }

            }


        }

    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            // 안 익은 토마토 남아있으면
            if(board[i][j] == 0){
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", last_day);

    return 0;
}