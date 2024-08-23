#include <stdio.h>

int main(){

    long long input;
    scanf("%lld", &input);

    int temp = 0;
    int m;

    /*
    temp: 0 -> 0+1
    */
    for(int i = 1; ; i++){
        temp += i;
        
        if(input <= temp){
            m = i;
            break;
        }
    }

    int sum = 0;
    for(int x = 1; x<m; x++){
        sum += x;
    }
    int rest = input - sum;

    if (m % 2 == 0){
        printf("%d/%d", rest, m-rest+1);

    } else {
        printf("%d/%d", m-rest+1, rest);
    }

    return 0;
}