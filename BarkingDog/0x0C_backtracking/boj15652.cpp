#include <stdio.h>
#include <stdlib.h>

int *arr;
int n, m;

//현재 k개가 확정됨.
//arr[k-1]까지 확정한 상태고, 지금 arr[k]를 정하는 함수.
void func(int k){

    if(k == m){
        //출력하고
        for(int i = 0; i<m; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    int start = (k == 0) ? 1 : arr[k-1];  
    for (int i = start; i <= n; i++) {
        arr[k] = i;   
        func(k + 1);  
    }
}


int main(){

    scanf("%d %d", &n, &m);

    //1부터 n까지의 숫자 가진 arr 배열 세팅
    arr = (int *)malloc(sizeof(int) * m);

    func(0);


    return 0;
}