#include <stdio.h>
#include <stdlib.h>

int main(){

    long long n, m;
    scanf("%lld %lld", &n, &m);

    if(n > m){
        long long temp = m;
        m = n;
        n = temp;
    }

    long long num = m-n-1;

    if(num < 0 ){
        printf("0\n");
        return 0;
    } 
    else {
        printf("%lld\n", num);
        for(long long i = n+1; i<m; i++){
            printf("%lld ", i);
        }
    }
    
    return 0;
}