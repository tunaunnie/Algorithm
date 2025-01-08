#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <tuple>

using namespace std;

int n;
int **board;

int now_x, now_y;
int new_x, new_y;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int name_islands() {
    int island_index = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) { // 섬의 첫 점을 발견
                island_index++;
                queue<pair<int, int>> q;
                q.push({i, j});

                while (!q.empty()) {
                    now_y = q.front().first;
                    now_x = q.front().second;
                    q.pop();

                    board[now_y][now_x] = island_index;

                    for (int k = 0; k < 4; k++) {
                        new_y = now_y + dy[k];
                        new_x = now_x + dx[k];

                        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && board[new_y][new_x] == 1) {
                            q.push({new_y, new_x});
                        }
                    }
                }
            }
        }
    }

    return island_index - 1;
}

int main(){

    scanf("%d", &n);

    board = (int **)malloc(sizeof(int *) * n);

    for(int i = 0; i<n; i++){
        board[i] = (int *)malloc(sizeof(int) * n);
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &board[i][j]);
        }
    }

    //대륙마다 이름 붙이기
    //반환값은 전체 섬 개수.
    int total_islands = name_islands();

    printf("\n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    //while문으로 각 바닷가 근접 cell에서 간척사업 하기
    //하다가 지역이 만나는 섬이 있으면, 그 turn 번째가 length.




    return 0;
}