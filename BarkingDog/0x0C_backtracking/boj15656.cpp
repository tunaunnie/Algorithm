#include <stdio.h>
#include <stdlib.h>

int n, m;
int *arr;
int *check;
int *answer;

int power(int p, int a){

    int answer = 1;

    for(int i = 0; i<p; i++){
        answer *= a;
    }

    return answer;
}

int find_index(int num){

    for(int i = 0; i<n; i++){
        if(arr[i] == num){
            return i;
        }
    }
}

//answer[0]~[k-1] 까지 정해짐
//k개 정해진 상태에서 answer[k]를 정하러 들어온 함수
void func(int k){

    if(k == m){
        int index = 0;

        for (int i = 0; i < m; i++) {
            index += find_index(answer[i]) * power(m-i-1, n);
        }

        if(check[index] == 0){
            for(int i = 0; i<m; i++){
                printf("%d ", answer[i]);
            }
            printf("\n");
            check[index] = 1;
            
        } 

        return;

    } else if (k == 0){
        for(int i = 0; i<n; i++){
            answer[0] = arr[i];
            func(1);
        }
    } else {
        for(int i = 0; i<n; i++){
                answer[k] = arr[i];
                func(k+1);
        }
    }
    
}

int main(){

    scanf("%d %d", &n, &m);
    arr = (int *)malloc(sizeof(int) * n);
    answer = (int *)malloc(sizeof(int) * m);    //m개를 고를 거임
    check = (int *)malloc(sizeof(int) * power(m, n)); //총 n*n개의 집합이 가능
    for(int i = 0; i<n*m; i++){
        check[i] = 0;
    }

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    //같은 수를 여러 번 골라도 됨, m개 선택
    func(0);

    return 0;
}