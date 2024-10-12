#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

int getlength(char *arr){

    int length = 0;
    while(arr[length] != '\0'){
        length++;
    }

    return length;
}

int main(){

    int n;
    scanf("%d", &n);

    char **board = (char **)malloc(sizeof(char *) * n);
    char **board2 = (char **)malloc(sizeof(char *) * n);

    for(int i = 0; i<n; i++){
        board[i] = (char *)malloc(sizeof(char) * 101);
        board2[i] = (char *)malloc(sizeof(char) * 101);
    }

    for(int i = 0; i<n; i++){
        scanf("%s", board[i]);
    }

    int m = getlength(board[0]);

    //board2에 똑같은 내용 복사하고 G->R로 수정
    for(int i = 0; i < n; i++){
        strcpy(board2[i], board[i]);
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(board2[i][j] == 'G'){
                board2[i][j] = 'R';
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int total_count = 0;
    int total_count2 = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){

            if(board[i][j] != 'X'){

                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                char temp = board[i][j];
                board[i][j] = 'X';
                total_count++;

                while(!q.empty()){

                    int now_x = q.front().first;
                    int now_y = q.front().second;
                    int new_x, new_y;
                    q.pop();

                    for(int k = 0; k<4; k++){
                        new_x = now_x + dx[k];
                        new_y = now_y + dy[k];

                        if(0 <= new_x && new_x < n && 0 <= new_y && new_y < m){
                            if(board[new_x][new_y] == temp){
                                q.push(make_pair(new_x, new_y));
                                board[new_x][new_y] = 'X';
                            }
                        }
                        
                    }

                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){

            if(board2[i][j] != 'X'){

                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                char temp = board2[i][j];
                board2[i][j] = 'X';
                total_count2++;

                while(!q.empty()){

                    int now_x = q.front().first;
                    int now_y = q.front().second;
                    int new_x, new_y;
                    q.pop();

                    for(int k = 0; k<4; k++){
                        new_x = now_x + dx[k];
                        new_y = now_y + dy[k];

                        if(0 <= new_x && new_x < n && 0 <= new_y && new_y < m){
                            if(board2[new_x][new_y] == temp){
                                q.push(make_pair(new_x, new_y));
                                board2[new_x][new_y] = 'X';
                            }
                        }
                        
                    }

                }
            }
        }
    }


    printf("%d %d", total_count, total_count2);


    return 0;
}