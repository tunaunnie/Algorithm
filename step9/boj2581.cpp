#include <stdio.h>
#include <math.h>

int check(int num){

    int temp = sqrt(num);

    for(int i = 2; i<=temp; i++){

        if(num%i == 0){
            return 0;
            // 0 반환 시 소수 아님
        }
    }

    return 1;
}

int main(){

    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    int sum = 0;
    int min = b;

    for (int i = a; i<=b; i++){
        
        int result;

        if(i == 1){
            result = 0;
        } else {
            result = check(i);
        }

        if (result == 1){
            sum += i;
            
            if(min >= i){
                min = i;
            }
        }
    }

    if(sum == 0){
        printf("-1");
    } else{
        printf("%d\n%d", sum, min);
    }

    return 0;
}