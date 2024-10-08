#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){

        int num;
        scanf("%d", &num);

        int *arr = (int *)malloc(sizeof(int) * num);
        //전부 열림
        for(int i = 0; i<num; i++){
            arr[i] = 0;
        }

        for(int i = 2; i<=num; i++){
            for(int j = 0; j<num; j++){
                //방 번호가 배수이면
                if( (j+1) % i == 0){
                    //열려있으면 잠그고
                    if(arr[j] == 0){
                        arr[j] = 1;
                    } else {  //잠겨있으면 열기
                        arr[j] = 0;
                    }
                }
            }
        }

        int count = 0;
        for(int i = 0 ; i<num; i++){
            if(arr[i] == 0){
                count++;
            }
        }

        printf("%d\n", count);

    }


    return 0;
}