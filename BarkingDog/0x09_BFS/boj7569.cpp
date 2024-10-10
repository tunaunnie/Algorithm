#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>
#include <tuple>

int n, m, h;
int ***boxes;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

using namespace std;

queue<pair<tuple<int, int, int>, int>> q;


int main(){

    scanf("%d %d %d", &m, &n, &h);
    boxes = (int ***)malloc(sizeof(int **) * h);

    for(int i = 0; i<h; i++){
        boxes[i] = (int **)malloc(sizeof(int *) * n);
        for(int j = 0; j<n; j++){
            boxes[i][j] = (int *)malloc(sizeof(int) * m);
            for(int k = 0; k<m; k++){
                boxes[i][j][k] = 0;
            }
        }
    } 

    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                boxes[i][j][k] = 0;
            }
        }
    }
    

    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                scanf("%d", &boxes[i][j][k]);
            }
        }
    }

    //익은 토마토는 전부 큐에 집어넣기
    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                if(boxes[i][j][k] == 1){
                    q.push(make_pair(make_tuple(k, j, i), 0));
                }
            }
        }
    }

    int last_day;

    while(!q.empty()){
        int now_x = get<0>(q.front().first);
        int now_y = get<1>(q.front().first);
        int now_z = get<2>(q.front().first);
        int now_day = q.front().second;
        last_day = now_day;

        q.pop();

        int new_x, new_y, new_z;

        for(int i = 0; i<6; i++){
            new_x = now_x + dx[i];
            new_y = now_y + dy[i];
            new_z = now_z + dz[i];

            if(0 <= new_x && new_x <m && 0 <= new_y && new_y < n && 0 <= new_z && new_z < h){
                if(boxes[new_z][new_y][new_x] == 0){
                    //익게 만들기
                    boxes[new_z][new_y][new_x] = 1;
                    //지금 익은 토마토 queue에 push
                    q.push(make_pair(make_tuple(new_x, new_y, new_z), now_day+1));
                }
            }

        }
    }

    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                if(boxes[i][j][k] == 0){
                    printf("-1");
                    return 0;
                }
            }
        }
    }

    printf("%d", last_day);

    return 0;
}