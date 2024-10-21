#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int main(){

    int l, r, c;
    scanf("%d %d %d", &l, &r, &c);

    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};

    while ( !(l==0 && r==0 && c==0)){

        char ***board = (char ***)malloc(sizeof(char **) * l);
        for(int i = 0; i<l; i++){
            board[i] = (char **)malloc(sizeof(char *) * r);
            for(int j = 0; j<r; j++){
                board[i][j] = (char *)malloc(sizeof(char) * c);
                for(int k = 0; k<c; k++){
                    board[i][j][k] = 0;
                }
            }
        }

        char *temp = (char *)malloc(sizeof(char) * (c+1));
        tuple<int, int, int> start_pos;
        tuple<int, int, int> exit_pos;
        

        for(int i = 0; i<l; i++){
            for(int j = 0; j<r; j++){
                scanf("%s", temp);
                for(int k = 0; k<c; k++){
                    board[i][j][k] = temp[k];
                    if(board[i][j][k] == 'S'){
                        start_pos = make_tuple(i, j, k);
                    }
                    if(board[i][j][k] == 'E'){
                        exit_pos = make_tuple(i, j, k);
                    }
                }
            }
            getchar(); //줄바꿈 받기
        }

        int now_x, now_y, now_z;
        int new_x, new_y, new_z;

        now_x = get<2>(start_pos);
        now_y = get<1>(start_pos);
        now_z = get<0>(start_pos);

        board[now_z][now_y][now_x] = '#';
        queue<tuple<int, int, int, int>> q;
        q.push(make_tuple(now_z, now_y, now_x, 0));
        int days = 0;
        int flag = 0;

        while(!q.empty()){

            now_x = get<2>(q.front());
            now_y = get<1>(q.front());
            now_z = get<0>(q.front());
            days = get<3>(q.front());
            q.pop();

            for(int m = 0; m<6; m++){
                new_x = now_x + dx[m];
                new_y = now_y + dy[m];
                new_z = now_z + dz[m];
                //printf("지금 xyz: %d, %d, %d\n", new_x, new_y, new_z);

                if( 0<= new_x && 0<= new_y && 0<=new_z && new_x<c && new_y<r && new_z<l){

                    if(board[new_z][new_y][new_x] == 'E'){
                        printf("Escaped in %d minute(s).\n", days+1);
                        flag = 1;
                        break;
                    }

                    if(board[new_z][new_y][new_x] == '.'){
                        board[new_z][new_y][new_x] = '#';
                        q.push(make_tuple(new_z, new_y, new_x, days+1));
                    }

                }

            }
            
            if(flag == 1 ) break;

        }

        if (flag == 0){
            printf("Trapped!");   
        }

        scanf("%d %d %d", &l, &r, &c);
    }




    return 0;
}