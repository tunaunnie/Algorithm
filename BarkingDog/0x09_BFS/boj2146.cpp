#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <tuple>

int n;
int **board;
int **check_board;
int *between_islands;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using namespace std;

// 섬 이름 붙이기
int name_islands() {
    int island_index = 1;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 && check_board[i][j] == 0) {
                // 새 섬 발견
                q.push({i, j});
                while (!q.empty()) {
                    auto [y, x] = q.front();
                    q.pop();
                    if (check_board[y][x]) continue;

                    check_board[y][x] = 1;
                    board[y][x] = island_index;

                    for (int d = 0; d < 4; d++) {
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if (ny >= 0 && nx >= 0 && ny < n && nx < n && !check_board[ny][nx] && board[ny][nx] == 1) {
                            q.push({ny, nx});
                        }
                    }
                }
                island_index++;
            }
        }
    }

    return island_index - 1;
}

// 다중 BFS로 최단 거리 계산
void find_shortest_bridge(int total_islands) {
    queue<tuple<int, int, int>> q;

    // 모든 섬의 경계 셀 추가
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 0) {
                for (int d = 0; d < 4; d++) {
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if (ny >= 0 && nx >= 0 && ny < n && nx < n && board[ny][nx] == 0) {
                        q.push({i, j, 0});  // (y, x, 거리)
                        check_board[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }

    while (!q.empty()) {
        auto [y, x, dist] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny >= 0 && nx >= 0 && ny < n && nx < n && !check_board[ny][nx]) {
                if (board[ny][nx] == 0) {
                    // 바다 탐색
                    q.push({ny, nx, dist + 1});
                    check_board[ny][nx] = 1;
                } else if (board[ny][nx] != board[y][x]) {
                    // 다른 섬 도달
                    int island1 = board[y][x] - 1;
                    int island2 = board[ny][nx] - 1;
                    int index1 = island1 * total_islands + island2;
                    int index2 = island2 * total_islands + island1;

                    if (between_islands[index1] == -1 || dist < between_islands[index1]) {
                        between_islands[index1] = dist;
                        between_islands[index2] = dist;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    board = (int **)malloc(sizeof(int *) * n);
    check_board = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++) {
        board[i] = (int *)malloc(sizeof(int) * n);
        check_board[i] = (int *)calloc(n, sizeof(int));
    }

    // 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // 섬 이름 붙이기
    int total_islands = name_islands();

    between_islands = (int *)malloc(sizeof(int) * total_islands * total_islands);
    for (int i = 0; i < total_islands * total_islands; i++) {
        between_islands[i] = -1;
    }

    // 다중 BFS로 최단 거리 계산
    find_shortest_bridge(total_islands);

    // 최단 거리 출력
    int shortest_length = 101;
    for (int i = 0; i < total_islands; i++) {
        for (int j = i + 1; j < total_islands; j++) {
            int index = i * total_islands + j;
            if (between_islands[index] != -1 && between_islands[index] < shortest_length) {
                shortest_length = between_islands[index];
            }
        }
    }
    printf("%d\n", shortest_length);

    // 메모리 해제
    for (int i = 0; i < n; i++) {
        free(board[i]);
        free(check_board[i]);
    }
    free(board);
    free(check_board);
    free(between_islands);

    return 0;
}
