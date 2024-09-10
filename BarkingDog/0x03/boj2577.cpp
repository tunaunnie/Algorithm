#include <stdio.h>

int main(){

    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);

    //0부터 9까지 개수 세기
    int count[10] = {0};

    long long result = a * b * c;

    while(result > 10){
        count[result % 10]++;
        result /= 10;
    }
    count[result]++;

    for(int i = 0; i<10; i++){
        printf("%d\n", count[i]);
    }

    return 0;
}