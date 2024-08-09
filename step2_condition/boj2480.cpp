#include <stdio.h>

int main(){

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(a==b && b==c){
        printf("%d", 10000+1000*a);
    } else if (a==b || a==c){
        printf("%d", 1000+100*a);
    } else if ( b==c ){
        printf("%d", 1000+100*b);
    } else {
        int temp = a;
        if(temp<b) temp=b;
        if(temp<c) temp=c;
        printf("%d", 100*temp);
    }

    return 0;
}