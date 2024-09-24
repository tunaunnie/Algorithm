#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){

    int n, k;
    scanf("%d %d", &n, &k);
    
    int *v = (int *)malloc(sizeof(int) * n);
    int *w = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }

    int **DP = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i<n; i++){
        DP[i] = (int *)malloc(sizeof(int) * k);
        for(int j = 0; j<k; j++){
            DP[i][j] = 0;
        }
    }

    //무게조건은 1부터 k까지 돌아감
    for(int j = 0; j<k; j++){

        //물건 1까지만, 2까지만, 3까지만, ... , n까지만 고려함
        for(int i = 0; i<n; i++){

            //지금 물건(한개)가 들어갈 수 있는 경우
            if(w[i] <= j+1){

                //지금 첫번째 물건까지만 보는 상황이라면 (이전 게 없음)
                if(i == 0){
                    DP[i][j] = v[i];
                } else { //비교할 이전 상황이 있는 경우
                 
                    //만약 남는 무게가 있다면
                    if(w[i] < j+1){

                        //바로 이전거 vs 지금거택하고 남은무게까지 활용한 경우
                        //중 더 가치가 높은 걸로 선택
                        DP[i][j] = max(DP[i-1][j], v[i] + DP[i-1][j-w[i]]);

                    }
                    else if (w[i] == j+1){ //남는 무게 없고 지금 딱 이거 들어가면 차는경우
                        
                        //지금 가치가 앞 가치보다 크면
                        if(v[i] > DP[i-1][j]){
                            DP[i][j] = v[i];
                        } else { //지금 가치가 앞 가치보다 작으면
                            DP[i][j] = DP[i-1][j];
                        }

                    }

                }
                
            } else { //지금 물건 한개도 못 들어가는 경우

                if (i == 0){ //앗 지금 1개까지만 보는 상황이면
                    DP[i][j] = 0;
                } else {
                    DP[i][j] = DP[i-1][j];
                }
            }

        }
    }

    //k만큼의 무게제한, n개의 물건 고려했을 때의 최대가치
    printf("%d", DP[n-1][k-1]);


    return 0;
}