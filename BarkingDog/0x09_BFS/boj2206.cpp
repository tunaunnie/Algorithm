#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int **board = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i<n; i++){
        board[i] = (int *)malloc(sizeof(int) * m);
        for(int j = 0; j<m; j++){
            board[i][j] = 0;
        }
    }

    char *temp = (char *)malloc(sizeof(char) * (m+1));
    for(int i = 0; i<n; i++){
        scanf("%s", temp);
        for(int j = 0; j<m; j++){
            board[i][j] = temp[j] - '0';
        }
    }

    if(n == 1 && m == 1){
        printf("1");
        return 0;
    }

    // 동적으로 visited 배열 할당
    int ***visited = (int ***)malloc(sizeof(int **) * n);
    for (int i = 0; i < n; i++) {
        visited[i] = (int **)malloc(sizeof(int *) * m);
        for (int j = 0; j < m; j++) {
            visited[i][j] = (int *)malloc(sizeof(int) * 2);
            visited[i][j][0] = 0;
            visited[i][j][1] = 0;
        }
    }

    //(0,0)에서 출발 -> (n-1, m-1)까지 가야 함
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(0, 0, 0, 1));
    visited[0][0][0] = 1;

    int now_x, now_y;
    int new_x, new_y;
    int flag;
    int distance;
    int able = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!q.empty()){

        now_x = get<0>(q.front());
        now_y = get<1>(q.front());
        flag = get<2>(q.front());
        distance = get<3>(q.front());

        q.pop();

        for(int i = 0; i<4; i++){
            new_x = now_x + dx[i];
            new_y = now_y + dy[i];
            
            if(0<= new_x && 0<= new_y && new_x<m && new_y<n){

                if(new_x == (m-1) && new_y == (n-1)){
                    printf("%d", distance+1);
                    able = 1;
                    return 0;
                }

                //플래그 상관없이 열려 있는 곳 이동
                if(board[new_y][new_x] == 0){

                    //지금 간 적 없다면
                    if(visited[new_y][new_x][flag] != 1){
                        q.push(make_tuple(new_x, new_y, flag, distance+1));
                         visited[new_y][new_x][flag] = 1;    
                    }
                } else if (board[new_y][new_x] == 1 && flag == 0){
                    if(visited[new_y][new_x][1] != 1){
                        q.push(make_tuple(new_x, new_y, 1, distance+1));
                        visited[new_y][new_x][1] = 1;
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