#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{

    int n = board.size(); // <- 나중에 돌아
    int m = board[0].size();  // <- 매번 돌아

    
    // 1이 하나라도 있으면 1 출력
    int flag = 0;
    if(n == 1 || m == 1){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] != 0){
                    flag = 1;
                }
            }
        }
        if(flag == 1){
            return 1;
        } else {
            return 0;
        }
    }
    
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(board[i][j] == 0){
                continue;
            } else { //0이 아닌 수면 검사
                if(board[i-1][j-1] != 0 && board[i][j-1] != 0 && board[i-1][j] != 0 ){
                    int value = min({board[i-1][j-1], board[i][j-1], board[i-1][j]});
                    //printf("지금 i랑 j: %d %d\n", i, j);
                    board[i][j] = value+1;
                }
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(answer < board[i][j]){
                answer = board[i][j];
            }
        }
    }


    return answer*answer;
}