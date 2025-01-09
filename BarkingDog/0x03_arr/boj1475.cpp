#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main(){

    int num;
    scanf("%d", &num);

    int digit = log10(num) + 1; //자릿수
    int numbers[10] = {0};

    int div;

    for(int i = 0; i<digit; i++){
        div = num%10;
        num /= 10;
        numbers[div]++;
    }

    int max = 0;
    int six_and_nine = (numbers[6] + numbers[9]) % 2 == 0 ? (numbers[6] + numbers[9]) / 2 : (numbers[6] + numbers[9]) / 2 + 1;

    for(int i = 0; i<10; i++){
        if(i == 6 || i == 9) continue;
        if(max < numbers[i]) max = numbers[i];
    }

    if(max > six_and_nine) {
        printf("%d", max);
    } else {
        printf("%d", six_and_nine);
    }

    return 0;
}