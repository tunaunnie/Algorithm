#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <utility>

using namespace std;

int **board;
int n, m;
int temp_size;

void go_inside(stack<pair<int, int>> *s, int x, int y){

    // 지금 잡은 좌표 push
    s->push(make_pair(x, y));
    //printf("지금 잡은 첫 좌표 : %d, %d\n", x, y);
    board[y][x] = 0;
    temp_size++;

    int top_x = s->top().first;
    int top_y = s->top().second;

    // 왼쪽 가능
    if (top_x - 1 >= 0 && board[top_y][top_x - 1] == 1)
    {
        go_inside(s, top_x-1, top_y);
    }
    // 오른쪽 가능
    if (top_x + 1 < m && board[top_y][top_x + 1] == 1)
    {
        go_inside(s, top_x+1, top_y);
    }
    // 위 가능
    if (top_y - 1 >= 0 && board[top_y - 1][top_x] == 1)
    {
        go_inside(s, top_x, top_y-1);
    }
    // 아래 가능
    if (top_y + 1 < n && board[top_y + 1][top_x] == 1)
    {
        go_inside(s, top_x, top_y+1);
    }

    // 나는 pop
    s->pop();

    if (s->empty())
    {
        return;
    }
}

int main(){

    // n은 세로 길이 (먼저 돌아), m은 가로 길이 (나중에 돌아).
    // 좌표는 항상 (m,n)
    scanf("%d %d", &n, &m);

    // n*m board 생성 및 초기화
    board = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    int stack_count = 0;
    int max_size = 0;

    // 배열을 쭉 돌면서, 1이면 해당 그림 전부 0으로 만들기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // 1인 애를 처음 찾으면
            if (board[i][j] == 1)
            {

                stack<pair<int, int>> s;
                stack_count++;
                temp_size = 0;                
                go_inside(&s, j, i);

                if(temp_size >= max_size){
                    max_size = temp_size;
                }

            }
        }
    }

    printf("%d\n%d", stack_count, max_size);

    return 0;
}