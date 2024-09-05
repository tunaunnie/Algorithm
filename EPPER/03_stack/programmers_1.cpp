#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stack;
    
    int n = board.size();
    int moves_size = moves.size();
    
    //moves에서 하나씩 인형 꺼내기
    for(int i = 0; i<moves_size; i++){
        
        int move = moves[i] -1;
        int doll = 0;
        
        //해당 열에서 가장 위에 있는 인형 찾기
        for(int j = 0; j<n; j++){
            
            if(board[j][move] != 0){
                doll = board[j][move];
                board[j][move] = 0;
                break;
            } 
        } 
        //doll=0으로 빠져나온다면, 빈 열임
        
        if(doll != 0) {
            
            if(!stack.empty() && stack.top() == doll){
                answer+=2;
                stack.pop();
            } else {
                stack.push(doll);
            }
        } 

    }
    
    
    return answer;
}