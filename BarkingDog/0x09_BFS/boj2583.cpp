#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>

using namespace std;

int main(){

    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);

    int **board = (int **)malloc(sizeof(int *) * m);
    for(int i = 0; i<m; i++){
        board[i] = (int *)malloc(sizeof(int) * n);
        for(int j = 0; j<n; j++){
            board[i][j] = 0;
        }
    }

    int start_x, start_y, end_x, end_y;
    for(int i = 0; i<k; i++){
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);

        for(int j = start_y; j< end_y; j++){
            for(int k = start_x; k<end_x; k++){
                board[j][k] = 1;
            }
        }
    }

    int now_x, now_y;
    int new_x, new_y;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int part_count = 0;
    queue<int> size_queue;

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] != 1){

                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                board[i][j] = 1;
                int size = 1;
                part_count++;

                while(!q.empty()){
                    now_y = q.front().first;
                    now_x = q.front().second;
                    q.pop();

                    for(int k = 0; k<4; k++){
                        new_y = now_y + dy[k];
                        new_x = now_x + dx[k];

                        if(0 <= new_x && new_x <n && 0<= new_y && new_y<m){
                            if(board[new_y][new_x] == 0){
                                q.push(make_pair(new_y, new_x));
                                board[new_y][new_x] = 1;
                                size++;
                            }
                        }
                    }
                }

            size_queue.push(size);

            }
        }
    }

    int *size_arr = (int *)malloc(sizeof(int) * part_count);
    for(int i = 0; i<part_count; i++){
        size_arr[i] = 0;
    }

    int index = 0;
    while(!size_queue.empty()){
        size_arr[index++] = size_queue.front();
        size_queue.pop();
    }

    for(int i = 0; i < part_count - 1; i++) {
        for(int j = i + 1; j < part_count; j++) {
            if(size_arr[i] > size_arr[j]) {
                int temp = size_arr[i];
                size_arr[i] = size_arr[j];
                size_arr[j] = temp;
            }
        }
    }


    printf("%d\n", part_count);
    for(int i = 0; i<part_count; i++){
        printf("%d ", size_arr[i]);
    }

}