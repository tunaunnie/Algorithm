#include <stdio.h>

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    int temp = a/100;
    int c = (a%10)*100 + (a/10 - temp*10)*10 + a/100;

    int temp2 = b/100;
    int d = (b%10)*100 + (b/10 - temp2*10)*10 + b/100;

    if(c>d) printf("%d", c);
    else printf("%d", d);

    return 0;
}



/*

734

7: 734를 100으로 나눈 몫 (a)
3: 734를 10으로 나눈 몫(73) - a*10
4: 734를 10으로 나눈 나머지

*/