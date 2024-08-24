#include <stdio.h>
#include <math.h>

int main(){

    long long a, b, v;
    scanf("%lld %lld %lld", &a, &b, &v);

    long long temp1 = v-a;
    long long temp2 = a-b;
    double temp3 = (double)temp1/temp2;

    int result = ceil(temp3) + 1;

    printf("%d", result);



    return 0;
}