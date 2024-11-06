#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int main(){

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    if(n == 1 && m == 1){
        printf("1");
        return 0;
    }

    int **board = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i<n; i++){
        board[i] = (int *)malloc(sizeof(int) * m);
        for(int j = 0; j<m; j++){
            board[i][j] = 0;
        }
    }

    for(int i = 0; i<n; i++){
        char *temp = (char *)malloc(sizeof(char) * (m+1));
        scanf("%s", temp);

        for(int j = 0; j<m; j++){
            board[i][j] = temp[j] - '0';
        }
    }



    //visited[][][0] : 해당 점까지 벽을 0번 부수고 갔을 때 가능한 최소 거리
    //visited[][][1] : 해당 점까지 벽을 1번 부수고 갔을 때 가능한 최소 거리
    //visited[][][k] : 해당 점까지 벽을 k번 부수고 갔을 때 가능한 최소 거리
    int ***visited = (int ***)malloc(sizeof(int **) * n);
    for(int i = 0; i<n; i++){
        visited[i] = (int **)malloc(sizeof(int *) * m);
        for(int j = 0; j<m; j++){
            visited[i][j] = (int *)malloc(sizeof(int) * (k+1));
            for(int h = 0; h<(k+1); h++){
                visited[i][j][h] = 0;
            }
        }
    }

    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(0, 0, 0, 1));
    visited[0][0][0] = 1;  //(1, 1)점을 0번 부수고 간 적 있음. (최소 거리 0)

    int now_x, now_y;
    int new_x, new_y;
    int break_count = 0;
    int now_distance;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int able = 0;

    while(!q.empty()){

        now_x = get<0>(q.front());
        now_y = get<1>(q.front());
        break_count = get<2>(q.front());
        now_distance = get<3>(q.front());

        q.pop();

        for(int i = 0; i<4; i++){

            new_x = now_x + dx[i];
            new_y = now_y + dy[i];

            if(new_x == (m-1) && new_y == (n-1)){
                printf("%d", now_distance+1);
                able = 1;
                return 0;
            }

            //board의 범위에 안 벗어나면
            if(0 <= new_x && new_x <m && 0<= new_y && new_y < n){

                //갈 수 있는 공간인 경우, 즉 부수고 갈 필요가 없음
                if(board[new_y][new_x] == 0){

                    if(visited[new_y][new_x][break_count] == 0){
                        visited[new_y][new_x][break_count] = 1; //방문한 것으로 기록 만들어 두고
                        q.push(make_tuple(new_x, new_y, break_count, now_distance+1));
                    }
                } else if (board[new_y][new_x] == 1 && break_count < k){ //벽이지만 부술 기회 남은 경우

                    
                    //간 적 없으면
                    if(visited[new_y][new_x][break_count+1] == 0){
                                               
                        visited[new_y][new_x][break_count+1] = 1; //방문한 것으로 기록 만들어 두고
                        q.push(make_tuple(new_x, new_y, break_count+1, now_distance+1));
                    }   

                }
            }
        }

    }

    if(able == 0){
        printf("-1");
        return 0;
    }

    return 0;
}