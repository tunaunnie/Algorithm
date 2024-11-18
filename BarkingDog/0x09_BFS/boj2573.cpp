#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int **board;
int **temp_board;
int **count_check; // 몇 번째 빙하 덩어리인지 check 용도
int year = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// temp_board에 일 년 지났을 때 빙하의 모습을 전부 저장해 둠.
void reduce_height()
{
    int new_x, new_y;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (board[i][j] > 0)
            {
                int count_zero = 0;
                for (int index = 0; index < 4; index++)
                {
                    new_x = j + dx[index];
                    new_y = i + dy[index];

                    if (0 <= new_x && new_x < m && 0 <= new_y && new_y < n)
                    {
                        if (board[new_y][new_x] == 0)
                        {
                            count_zero++;
                        }
                    }
                }
                temp_board[i][j] = max(0, board[i][j] - count_zero);
            } else {
                temp_board[i][j] = 0;
            }
        }
    }
}

int count_glacier()
{

    // count_check 배열 초기화
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            count_check[i][j] = -1;
        }
    }

    int glacier_index = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // 아직 덩어리가 정해지지 않은, 얼음 cell이면
            // 그 얼음 cell을 선두로 연결된 모든 얼음 cell의 덩어리 이름 붙여주기
            // 여기에 들어온 횟수 == 빙하 덩어리 개수 == glacier_index 값.
            if (board[i][j] != 0 && count_check[i][j] == -1)
            {
                glacier_index++;

                int now_x, now_y;
                int new_x, new_y;

                queue<pair<int, int>> q;
                q.push(make_pair(i, j));

                while (!q.empty())
                {

                    now_x = q.front().second;
                    now_y = q.front().first;

                    q.pop();

                    for (int index = 0; index < 4; index++)
                    {
                        new_x = now_x + dx[index];
                        new_y = now_y + dy[index];

                        if (0 <= new_x && new_x < m && 0 <= new_y && new_y < n)
                        {
                            if (board[new_y][new_x] != 0 && count_check[new_y][new_x] == -1)
                            {
                                q.push(make_pair(new_y, new_x));
                                count_check[new_y][new_x] = glacier_index;
                            }
                        }
                    }
                }
               
            }
        }
    }

    return glacier_index;
}

int main()
{

    scanf("%d %d", &n, &m);
    board = (int **)malloc(sizeof(int *) * n);
    temp_board = (int **)malloc(sizeof(int *) * n);
    count_check = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(sizeof(int) * m);
        temp_board[i] = (int *)malloc(sizeof(int) * m);
        count_check[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++)
        {
            board[i][j] = 0;
            temp_board[i][j] = 0;
            count_check[i][j] = -1;
        }
    }

    int water_flag = 0;
    int highest = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 0)
            {
                water_flag = 1;
            }
            if (board[i][j] > highest)
            {
                highest = board[i][j]; // 가장 높은 빙산의 높이 구하기
            }
        }
    }

        int glacier_count = count_glacier();
        //printf("지금 빙하 덩어리 개수: %d\n", glacier_count);

    // 물이 없어서 녹을 수 없으므로 0 출력
    if (water_flag != 1)
    {
        printf("0");
        return 0;
    }

    while(true)
    { 

        year++;
        //일 년 뒤 높이 계산
        reduce_height();
        
        //계산한 높이 board로 옮기기
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = temp_board[i][j];
                //printf("%d", board[i][j]);
            }
            //printf("\n");
        }

        //업데이트된 board 에서 개수 세기
        int glacier_count = count_glacier();
        //printf("지금 빙하 덩어리 개수: %d\n", glacier_count);
        
        if (glacier_count > 1)
        {
            printf("%d", year);
            return 0;
        }

        if(glacier_count == 0){
            printf("0\n");
            return 0;
        }
    }

    return 0;
}