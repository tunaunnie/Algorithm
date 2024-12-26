#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <tuple>
#include <utility>

int n;
int **board;
int **check_board;
int *between_islands;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using namespace std;

int name_islands()
{

    queue<tuple<int, int, int>> q;

    int island_index = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // 한 섬 덩어리의 첫 cell 발견
            // 이 섬 덩어리의 모든 cell에 이름 붙이기
            if (board[i][j] == 1 && check_board[i][j] == 0)
            {
                q.push(make_tuple(i, j, island_index));

                while (!q.empty())
                { // 인접하게 붙어있는 모든 섬 덩어리에 찾아서 이름 붙이기

                    int now_y = get<0>(q.front());
                    int now_x = get<1>(q.front());
                    int now_length = get<2>(q.front());
                    q.pop();

                    board[now_y][now_x] = island_index;
                    check_board[now_y][now_x] = 1;

                    for (int l = 0; l < 4; l++)
                    {
                        int new_x = now_x + dx[l];
                        int new_y = now_y + dy[l];

                        if (0 <= new_x && new_x < n && 0 <= new_y && new_y < n)
                        {
                            if (board[new_y][new_x] == 1 && check_board[new_y][new_x] == 0)
                            {
                                q.push(make_tuple(new_y, new_x, now_length));
                            }
                        }
                    }
                } // 현재 섬 덩어리의 모든 cell이 이 while문 안에서 한 번씩 돎.
                island_index++;
            }
        }
    }

    return island_index - 1;
}

void find_distances(int total_islands)
{
    queue<tuple<int, int, int>> q; // (y, x, 거리)

    // 모든 섬의 경계 셀을 큐에 추가
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] > 0)
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if (ny >= 0 && nx >= 0 && ny < n && nx < n && board[ny][nx] == 0)
                    {
                        q.push({i, j, 0}); // 섬 경계에서 시작
                        check_board[i][j] = board[i][j]; // 섬 번호로 방문 표시
                        break;
                    }
                }
            }
        }
    }

    // BFS로 섬 간 최소 거리 계산
    while (!q.empty())
    {
        auto [y, x, dist] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny >= 0 && nx >= 0 && ny < n && nx < n)
            {
                if (check_board[ny][nx] == 0)
                {
                    if (board[ny][nx] == 0)
                    {
                        // 바다 탐색
                        q.push({ny, nx, dist + 1});
                        check_board[ny][nx] = check_board[y][x];
                    }
                    else if (board[ny][nx] != check_board[y][x])
                    {
                        // 다른 섬에 도달
                        int start_island = check_board[y][x] - 1;
                        int target_island = board[ny][nx] - 1;
                        int index1 = start_island * total_islands + target_island;
                        int index2 = target_island * total_islands + start_island;

                        if (between_islands[index1] == -1 || dist + 1 < between_islands[index1])
                        {
                            between_islands[index1] = dist + 1;
                            between_islands[index2] = dist + 1;
                        }
                    }
                }
            }
        }
    }
}



int main()
{

    scanf("%d", &n);

    board = (int **)malloc(sizeof(int *) * n);
    check_board = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(sizeof(int) * n);
        check_board[i] = (int *)malloc(sizeof(int) * n);

        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
            check_board[i][j] = 0;
        }
    }

    // 입력 받기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    int total_islands;
    // 각각 섬에 이름 붙이기
    total_islands = name_islands();

    between_islands = (int *)malloc(sizeof(int) * total_islands * total_islands);
    for (int i = 0; i < total_islands * total_islands; i++) {
        between_islands[i] = -1;
    }

    find_distances(total_islands);

    int shortest_length = 101;
    for (int i = 0; i < total_islands; i++)
    {
        for (int j = i + 1; j < total_islands; j++)
        {
            int index = i * total_islands + j;
            if (shortest_length > between_islands[index] && between_islands[index] != -1)
            {
                shortest_length = between_islands[index];
            }
        }
    }
    printf("%d", shortest_length);

    return 0;
}