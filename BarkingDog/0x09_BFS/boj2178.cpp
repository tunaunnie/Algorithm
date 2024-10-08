#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

int n, m;
int **board;
int **dis;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

// (0,0)에서 시작
void func(int x, int y) {
    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = now_x + dx[i];
            int new_y = now_y + dy[i];
            //printf("지금 검사 중인 좌표: %d, %d\n", new_x, new_y);

            if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m && board[new_x][new_y] == 1) {
                dis[new_x][new_y] = dis[now_x][now_y] + 1;
                board[new_x][new_y] = 0; // 방문 표시
                q.push(make_pair(new_x, new_y));
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    board = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        char *line = (char *)malloc(sizeof(char) * (m + 1));
        scanf("%s", line);
        for (int j = 0; j < m; j++) {
            board[i][j] = line[j] - '0';
        }
        free(line); // 메모리 해제
    }

    dis = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        dis[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            dis[i][j] = -1;
        }
    }

    dis[0][0] = 1;
    board[0][0] = 0; // 방문 표시
    q.push(make_pair(0, 0));
    func(0, 0);

    // // 확인용 출력문
    // printf("distance board\n");
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%d ", dis[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d", dis[n - 1][m - 1]);

    return 0;
}
