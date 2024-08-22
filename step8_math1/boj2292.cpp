#include <stdio.h>

int main(){

    long long input;
    scanf("%lld", &input);

    if(input == 1) {
        printf("1");
        return 0;
    }

    long long num = 2;
    
    for (int i=1; ; i++){
        if (input < num+6*i){
            printf("%d", i+1);
            break;
        }
        else{
            num+= 6*i;
        }
    }

    return 0;
}