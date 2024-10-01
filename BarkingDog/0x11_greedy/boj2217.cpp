#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main(){

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n, desc);

    int *candidate = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        candidate[i] = (i+1) * arr[i];
    }

    int max = candidate[0];
    for(int i = 0; i<n; i++){
        if(candidate[i] >= max){
            max = candidate[i];
        }
    }

    printf("%d", max);

    return 0;
}