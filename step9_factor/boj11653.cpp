#include <stdio.h>
#include <math.h>

int main(){

    int num;
    scanf("%d", &num);

    if(num == 1){
        return 0;
    }

    for(int i = 2; i<=num; i++ ){
        while(num % i == 0){
            printf("%d\n", i);
            num /= i;
        }
    }

    return 0;

}