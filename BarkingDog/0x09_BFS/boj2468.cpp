#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int **board = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i<n; i++){
        board[i] = (int *)malloc(sizeof(int) * n);
        for(int j = 0; j<n; j++){
            board[i][j] = 0;
        }
    }

    int min_h = 101;
    int max_h = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int max_count = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &board[i][j]);

            if(min_h > board[i][j]){
                min_h = board[i][j];
            }

            if(max_h < board[i][j]){
                max_h = board[i][j];
            }
        }
    }

    //내리는 비의 양을 min부터 max 높이까지 다 돌려보면서
    //그 때 안 잠기는 영역 수 세기
    for(int r = 0; r<= max_h; r++){

        //한 번 시뮬레이션 할 때마다 board 복사하기
        int **temp_board = (int **)malloc(sizeof(int *) * n);
        for(int i = 0; i<n; i++){
            temp_board[i] = (int *)malloc(sizeof(int) * n);
            for(int j = 0; j<n; j++){
                temp_board[i][j] = board[i][j];
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){

                //안 잠기는 곳은 1, 잠기는 곳은 0 처리
                if(temp_board[i][j] > r){
                    temp_board[i][j] = 1;
                } else {
                    temp_board[i][j] = 0;
                }
            }
        }

        int now_x, now_y;
        int new_x, new_y;

        //지금 강수량에서 나오는 part의 개수
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){

                //안 잠기는 영역의 첫 번째 원소 나온 경우
                if(temp_board[i][j] == 1){

                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    temp_board[i][j] = 0;
                    //printf("지금 강수량: %d, 첫번째 영역: (%d, %d)\n", r, i, j);
                    count++;

                    while(!q.empty()){

                        now_x = q.front().first;
                        now_y = q.front().second;
                        q.pop();

                        for(int k = 0; k<4; k++){
                            new_x = now_x + dx[k];
                            new_y = now_y + dy[k];

                            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n){
                                if(temp_board[new_x][new_y] == 1){
                                    q.push(make_pair(new_x, new_y));
                                    temp_board[new_x][new_y] = 0;
                                }
                            }
                        }
                    }

                }


            }
        }

        if(count >= max_count){
            max_count = count;
        }
    }

    printf("%d", max_count);



    return 0;
}