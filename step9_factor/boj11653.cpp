#include <stdio.h>
#include <math.h>

//소수면 1 반환, 아니면 0 반환
int is_prime(int num){

    if(num == 2){
        return 1;
    } else if (num == 3){
        return 1;
    } else{
        for(int i=2; i<=sqrt(num); i++){
            if(num % i == 0){
                return 0;
            }
        }
    }

    return 1;
}

int main(){

    int num;
    scanf("%d", &num);

    if(num == 1){
        return 0;
    }

    for(int i = 2; i<=num; i++){

    }

    return 0;
}