#include <stdio.h>

int main(){

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int min, mid, max;

    if(a > b && a > c) max = a;
    else if(b > c && b> a) max = b;
    else if(c > a && c> b) max = c;

    if(a < b && a < c) min = a;
    else if(b < c && b< a) min = b;
    else if(c < a && c< b) min = c;

    mid = a+b+c-min-max;

    printf("%d %d %d", min, mid, max);
    

    return 0;
}