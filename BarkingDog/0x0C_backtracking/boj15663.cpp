#include <stdio.h>
#include <stdlib.h>

int n, m;
int *arr;
int *arr2;
int *answer;
int *check;
int *check2;

int power(int p, int a){
    int answer = 1;
    for(int i = 0; i<p; i++){
        answer *= a;
    }
    return answer;
}

int find_index(int num){

    for(int i = 0; i<n; i++){
        if(arr2[i] == num){
            return i;
        }
    }
}

int find_index2(int num){
    for(int i = 0; i<n; i++){
        if(num == arr[i] && check2[i] == 0){
            return i;
        } else if (num == arr[i] && check2[i] == 1){
            continue;
        }
    }
    return -1;
    //없음
}


//k개 정해졌고, answer[k]을 정하러 들어온 함수
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
            check[index] = 1;
            printf("\n");
        } 

        return;

          

    } else {
        for(int i = 0; i<n; i++){
            int index = find_index2(arr[i]);

            if(index == -1){
                continue;
            } else {
                answer[k] = arr[i];
                check2[index] = 1;
                func(k+1);
                check2[index] = 0;
            }
        }
    }
}

int main(){

    scanf("%d %d", &n, &m);
    arr = (int *)malloc(sizeof(int) * n);
    arr2 = (int *)malloc(sizeof(int) * n); //중복 없는 배열 저장
    answer = (int *)malloc(sizeof(int) * m);
    check = (int *)malloc(sizeof(int) * power(m, n));
    check2 = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i<power(m, n); i++){
        check[i] = 0;
    }

    for(int i = 0; i<n; i++){
        check2[i] = 0;
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

    arr2[0] = arr[0];
    int j = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] != arr2[j - 1]){
            arr2[j] = arr[i];
            j++;
        }
    }

    func(0);

    return 0;
}