#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int find_friend_index(string friend_name, vector<string> friends, int friends_n){

    int index;
    
    for(int i = 0; i<friends_n; i++){
        if(friend_name == friends[i]){
            return i;
        }
    }
    
    return -1;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int n = friends.size();
    int gifts_n = gifts.size();
    
    int **board = (int **)malloc(sizeof(int *) * n );
    for(int i = 0; i<n; i++){
        board[i] = (int *)malloc(sizeof(int) * n);
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            board[i][j] = 0;
        }
    }
    
    //board 채우기
    for(int i = 0; i<gifts_n; i++){
        int index = gifts[i].find(' ');
        
        string giver = gifts[i].substr(0, index);
        string taker = gifts[i].substr(index+1);
        
        int giver_index = find_friend_index(giver, friends, gifts_n);
        int taker_index = find_friend_index(taker, friends, gifts_n);
        
        if(giver_index != -1 && taker_index != -1){
            board[taker_index][giver_index]++;
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
    //선물지수 저장
    int *gift_score = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        
        int received_sum = 0;
        int give_sum = 0;
        
        for(int j = 0; j<n; j++){
            received_sum += board[j][i];
            give_sum += board[i][j];
        }
        
        gift_score[i] = received_sum - give_sum;
    }
    printf("gift score\n");
    for(int i = 0; i<n; i++){
        printf("%d, ", gift_score[i]);
    }
    
    int *each_gift = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        each_gift[i] = 0;
    }
    
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            printf("\n지금 %d랑 %d\n", i, j);
            
            //주고받은 기록이 있으면
            if( board[i][j] != 0 || board[j][i] != 0){
                printf("기록 있음\n");
                int more_giver;
                if(board[i][j] > board[j][i]){
                    more_giver = j;
                } else if (board[i][j] < board[j][i]){
                    more_giver = i;               
                } else { //주고받은 기록이 같은 경우, 선물지수 비교
                    more_giver = -1;
                }
                
                //더 많이 준 사람 있음
                if(more_giver != -1){
                    printf("%d가 더 많아서 증가\n", more_giver);
                    each_gift[more_giver]++;
                    
                } else { //선물지수 비교
                    int bigger_score;
                    if(gift_score[i] > gift_score[j]){
                        bigger_score = i;
                    } else if (gift_score[i] < gift_score[j]){
                        bigger_score = j;
                    } else { //점수까지 같은 경우
                        bigger_score = -1;
                    }
                
                    if(bigger_score != -1){
                        printf("%같이 줘서 선물지수 비교 : %d가 더 많아서 증가\n", bigger_score);
                        each_gift[bigger_score]++;
                    }
                }
                
            } else { //주고받은 기록이 없으면
                printf("기록 없음\n");
                int bigger_score;
                if(gift_score[i] > gift_score[j]){
                    bigger_score = i;
                } else if (gift_score[i] < gift_score[j]){
                    bigger_score = j;
                } else { //점수까지 같은 경우
                    bigger_score = -1;
                }
                
                if(bigger_score != -1){
                    printf("같이 줘서 선물지수 비교 : %d가 더 많아서 증가\n", bigger_score);
                    each_gift[bigger_score]++;
                }
                
            }
        }
    }
    
    answer = each_gift[0];
    for(int i = 0; i<n; i++){
        if(answer <= each_gift[i]){
            answer = each_gift[i];
        }
    }
    
    
    return answer;
}