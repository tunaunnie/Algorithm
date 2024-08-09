#include <stdio.h>

int main(){

    long a, b, c;
    long temp = 0;

    scanf("%ld %ld %ld", &a, &b, &c);

    temp = a+b;
    temp = temp+c;
    printf("%ld", temp);

    return 0;
}