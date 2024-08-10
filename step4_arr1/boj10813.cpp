#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int *arr = (int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        arr[i] = i+1;
    }

    for(int k=0; k<m; k++){
        int i, j, temp;
        scanf("%d %d", &i, &j);
        temp = arr[i-1];
        arr[i-1] = arr[j-1];
        arr[j-1] = temp;
    }

    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}