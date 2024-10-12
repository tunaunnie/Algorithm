#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    int m, n, k;
    int **board;

    int x, y;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for(int i = 0; i<t; i++){

        scanf("%d %d %d", &m, &n, &k);

        //board판 메모리 할당 및 0으로 전부 초기화
        board = (int **)malloc(sizeof(int *) * n);
        for(int i = 0; i<n; i++){
            board[i] = (int *)malloc(sizeof(int) * m);
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                board[i][j] = 0;
            }
        }

        //board판에 배추 심기
        for(int i = 0; i<k; i++){
            scanf("%d %d", &x, &y);
            board[y][x] = 1;
        }

        queue<pair<int, int>> q;

        int now_x, now_y;
        int new_x, new_y;
        int total_count = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                
                if(board[i][j] == 1){

                    total_count++;

                    q.push(make_pair(i, j));
                    board[i][j] = 0;
                    
                    while(!q.empty()){
                        now_x = q.front().first;
                        now_y = q.front().second;
                        q.pop();

                        for(int k = 0; k<4; k++){
                            new_x = now_x + dx[k];
                            new_y = now_y + dy[k];

                            if(0 <= new_x && new_x < n && 0 <= new_y && new_y < m){
                                if(board[new_x][new_y] == 1){
                                    q.push(make_pair(new_x, new_y));
                                    board[new_x][new_y] = 0;
                                }
                            }
                        }


                    }


                }



            }
        }

        printf("%d\n", total_count);

    }




    return 0;
}