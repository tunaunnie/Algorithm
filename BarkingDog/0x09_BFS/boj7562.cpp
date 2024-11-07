#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

int main() {
    int n, h;
    int start_x, start_y;
    int end_x, end_y;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        scanf("%d", &h);
        
        int **board = (int **)malloc(sizeof(int *) * h);
        for(int j = 0; j < h; j++) {
            board[j] = (int *)malloc(sizeof(int) * h);
            for(int k = 0; k < h; k++) {
                board[j][k] = -1;
            }
        }
        

        scanf("%d %d", &start_x, &start_y);
        scanf("%d %d", &end_x, &end_y);

        if(start_x == end_x && start_y == end_y) {
            printf("0\n");
            continue;
        }

        board[start_y][start_x] = 0;

        queue<tuple<int, int>> q;
        q.push(make_tuple(start_x, start_y));

        int now_x, now_y;
        int new_x, new_y;

        int dx[4] = {-2, -1, 1, 2};
        int dy[4] = {-2, -1, 1, 2};

        bool stop_flag = false;

        while(!q.empty() && !stop_flag) {
            now_x = get<0>(q.front());
            now_y = get<1>(q.front());

            q.pop();

            for(int n = 0; n < 4; n++) {
                for(int m = 0; m < 4; m++) {
                    int temp = dx[n] + dy[m];

                    if(temp == 1 || temp == -1 || temp == -3 || temp == 3) {
                        new_x = now_x + dx[n];
                        new_y = now_y + dy[m];

                        if(new_x == end_x && new_y == end_y) {
                            printf("%d\n", board[now_y][now_x] + 1);
                            stop_flag = true;
                            break;
                        }

                        if(0 <= new_x && 0 <= new_y && new_x < h && new_y < h) {
                            if(board[new_y][new_x] == -1) { //여기에 처음 도착한 경우
                                board[new_y][new_x] = board[now_y][now_x] + 1;
                                q.push(make_tuple(new_x, new_y));
                            }
                        }
                    }
                }
                if (stop_flag) break;
            }
        }

        
        for(int j = 0; j < h; j++) {
            free(board[j]);
        }
        free(board);
    } //테스트 케이스 한 번 끝남

    return 0;
}
