#include <stdio.h>
#include <stdlib.h>

int n, m;
int *subset;

//subset[k-1]까지 확정했고, 이제 subset[k] 숫자 정해주는 함수.
//중복 가능함. 앞의 것보다 같거나 큰 값만 넣을 수 있음
void func(int k){

    if(k == m){ //subset 다 찼으면 subset 전체 print하고 return.
        for(int i = 0; i<m; i++){
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    } else { //아직 다 안 찼으면

        //지금이랑 같거나 큰 수로 subset 자릿수 채우기
        for(int i = 1; i<=n; i++){
            subset[k] = i;
            func(k+1);
        }
    }
}

int main(){

    scanf("%d %d", &n, &m);
    
    subset = (int *)malloc(sizeof(int) * m);


    //1부터 n까지의 숫자 중에
    //m개를 고르기, 근데 중복도 괜찮음.
    for(int i = 0; i<n; i++){

        //subset 전체 초기화
        for(int i = 0; i<m; i++){
            subset[i] = 0;
        }

        subset[0] = i+1; //1으로, 2로, ..., n으로, ... 시작하는 수열들. 첫번째 자리만 정해주고 넘겨주기
        func(1);
    }


    return 0;
}