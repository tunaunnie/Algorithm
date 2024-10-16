#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);  

    int **board = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++){
        board[i] = (int *)malloc(sizeof(int) * n);
    }

    for(int i = 0; i < n; i++){
        char *row = (char *)malloc(sizeof(char) * (n+1));  
        scanf("%s", row);  

        for(int j = 0; j < n; j++){
            board[i][j] = row[j] - '0';  
        }
    }

    int now_x, now_y;
    int new_x, new_y;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<int> size_count;
    int size;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(board[i][j] == 1){

                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                board[i][j] = 0;
                size = 1;

                // 한 단지 내 (인접한) 모든 집 찾기
                while(!q.empty()){

                    now_x = q.front().first;
                    now_y = q.front().second;
                    q.pop();

                    for(int k = 0; k < 4; k++){
                        new_x = now_x + dx[k];
                        new_y = now_y + dy[k];

                        if(0 <= new_x && new_x < n && 0 <= new_y && new_y < n){
                            if(board[new_x][new_y] == 1){
                                q.push(make_pair(new_x, new_y));
                                board[new_x][new_y] = 0;
                                size++;
                            }
                        }
                    }
                }

                //printf("current size: %d\n", size);
                size_count.push(size);
            }
        }
    }

    int m = size_count.size();
    int *size_arr = (int *)malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++){
        size_arr[i] = size_count.front();
        size_count.pop();
    }

    // 선택 정렬로 오름차순 정렬
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            if(size_arr[i] > size_arr[j]){
                int temp = size_arr[j];
                size_arr[j] = size_arr[i];
                size_arr[i] = temp;
            }
        }
    }

    printf("%d\n", m);
    for(int i = 0; i < m; i++){
        printf("%d\n", size_arr[i]);
    }

    
    for(int i = 0; i < n; i++){
        free(board[i]);
    }
    free(board);
    free(size_arr);

    return 0;
}
