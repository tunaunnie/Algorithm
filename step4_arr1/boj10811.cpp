#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int *arr = (int *)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        arr[i] = i+1;
    }

    for(int k = 0; k<m; k++){
        int i, j;
        scanf("%d %d", &i, &j);   //i번부터 j번까지의 순서를 역순으로

        int loop = (j-i+1)/2;
        for(int index = 0; index<loop; index++){
            //arr[index+i-1]와 arr[j-index-1]를 교환
            int temp = arr[index+i-1];
            arr[index+i-1]= arr[j-index-1];
            arr[j-index-1] = temp;
        }
    }
    
    for(int i=0; i<n; i++){
            printf("%d ", arr[i]);
    }

    return 0;
}

/*

1 2 3 4 5 6 7 8 9 10

만약 1부터 4까지를 역순으로 (갯수가 짝수)

temp =2 (갯수/2) 만들어서, index= 0부터 temp까지
index랑 temp-index 를 서로 바꿔주면 됨 (index++)


1 2 3 4 5 6 7 8 9 10

만약 1부터 3까지를 역순으로 (갯수가 홀수)
temp = 1 (갯수 /2)

중간거는 내버려두면됨

*/