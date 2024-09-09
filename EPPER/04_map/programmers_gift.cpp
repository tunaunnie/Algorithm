#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    
    int friends_length = friends.size();
    int gifts_length = gifts.size();
    
    // 2D 벡터로 map을 초기화 (0으로 초기화된 2차원 벡터)
    vector<vector<int>> gift_map(friends_length, vector<int>(friends_length, 0));
    
    vector<int> give(friends_length, 0);  // 각 친구가 준 선물의 수
    vector<int> take(friends_length, 0);  // 각 친구가 받은 선물의 수
    vector<int> gift_score(friends_length, 0);  // 선물 점수
    vector<int> count(friends_length, 0);  // 최종 카운트
    
    // map(주고받은 기록), give, take 값 초기화
    for(int i = 0; i < gifts_length; i++) {
        string a, b;
        
        int pos = gifts[i].find(' ');
        a = gifts[i].substr(0, pos);
        b = gifts[i].substr(pos + 1);
        
        int giver = -1, taker = -1;
        
        // friends 배열에서 주는 사람과 받는 사람을 찾음
        for(int j = 0; j < friends_length; j++) {            
            if(a == friends[j]){
                give[j]++;
                giver = j;
            }
            if(b == friends[j]){
                take[j]++;
                taker = j;
            }
        }
        
        // giver 또는 taker가 유효하지 않으면 무시
        if (giver != -1 && taker != -1) {
            gift_map[giver][taker]++;  // 선물 기록
        }
    }
    
    // 선물지수 값 초기화 (준 선물 - 받은 선물)
    for(int i = 0; i < friends_length; i++) {
        int score = give[i] - take[i];
        gift_score[i] = score;
    }
    
    // 비교 및 카운팅
    for(int i = 0; i < friends_length; i++) {
        for(int j = i + 1; j < friends_length; j++) {  // i < j 로 중복 방지
            if(i == j) continue;
            
            if(gift_map[i][j] != 0 || gift_map[j][i] != 0) { // 기록이 있는 경우
                if(gift_map[i][j] > gift_map[j][i]) {  // A가 더 많이 줌
                    count[i]++;
                } else if (gift_map[i][j] < gift_map[j][i]) {  // B가 더 많이 줌
                    count[j]++;
                } else {  // 같은 횟수로 주고받음
                    if(gift_score[i] > gift_score[j]) {
                        count[i]++;
                    } else if(gift_score[i] < gift_score[j]) {
                        count[j]++;
                    }
                }
            } else {  // 기록이 없는 경우
                if(gift_score[i] > gift_score[j]) {
                    count[i]++;
                } else if(gift_score[i] < gift_score[j]) {
                    count[j]++;
                }
            }
        }
    }
    
    // 가장 높은 점수를 가진 사람 찾기
    int answer = count[0];
    for(int i = 1; i < friends_length; i++) {
        if(answer < count[i]) {
            answer = count[i];
        }
    }
    
    return answer;  
}

int main(){

    vector<string> friends = {"muzi", "ryan", "frodo", "neo"};  
    vector<string> gifts = {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", 
                            "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"};

    int answer = solution(friends, gifts);

    printf("%d\n", answer);

    return 0;
}
