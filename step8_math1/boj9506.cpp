#include <stdio.h>
#include <stdlib.h>


int main(){

    int num;

    while(~scanf("%d", &num)){
        if(num == -1) break;

        int *factors = (int *)malloc(sizeof(int) * 100);
        int pos = 0;
        int sum = 0;

        for(int i = 1; i<num; i++){
            
            //지금 수가 약수라면
            if(num % i == 0){
                sum += i;
                factors[pos++] = i;
            }
        }

        //지금 pos: 약수의 개수

        if(sum == num){
            printf("%d = ", num);
            for(int i = 0; i<pos; i++){
                printf("%d", factors[i]);
                if(i != pos-1){
                    printf(" + ");
                }
            }
            printf("\n");
        } else{
            printf("%d is NOT perfect.\n", num);
        }

    }


    return 0;
}