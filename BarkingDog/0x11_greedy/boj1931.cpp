#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int **table = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i<n; i++){
        table[i] = (int *)malloc(sizeof(int ) * 2);
        for(int j = 0; j<2; j++){
            table[i][j] = 0;
        }
    }

    int *check_if_used = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        check_if_used[i] = 0;
    }

    for(int i = 0; i<n; i++){
        scanf("%d %d", &table[i][0], &table[i][1]);
    }

    int count = 0;
    int index = 0;

    int time = table[0][0];

    for(int i = 0; i<n; i++){
        if(time < table[i][0]){
            time = table[i][0];
            index = i;
        }
    }

    count++;
    check_if_used[index] = 1; //맨 마지막 회의는 사용한 것으로 침

    int flag = 0;
    while (flag == 0){

        flag = 1;
        vector<int> candidate;

        //현재 time보다 end값이 작은 회의가 있는지 찾기.
        for(int i = 0; i<n; i++){

            //만약 이 회의가 현재 time보다 end값이 작거나 같으면 후보에 넣어둠
            if(time >= table[i][1] && check_if_used[i] == 0){
                flag = 0;
                candidate.push_back(i);
            }
        }

        //만약 위에서 하나도 못 찾았으면 종료
        if(flag == 1){
            break;
        } 
        else {        //만약 위에서 찾았으면 진행함.

            int max_start = table[candidate[0]][0];
            
            //후보군 중 가장 start 시간이 큰 회의를 찾음 (시작 시간과 회의 인덱스)
            for(int i = 0; i<candidate.size(); i++){
                if(max_start <= table[candidate[i]][0]){
                    max_start = table[candidate[i]][0];
                    index = candidate[i];
                }
            }

            time = max_start;
            check_if_used[index] = 1;
            count++;
        }
    }

    printf("%d", count);
    


    return 0;
}