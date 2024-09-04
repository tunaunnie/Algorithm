#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    char *array = (char *)malloc(sizeof(char)*(n+1));
    scanf("%s", array);

    int *hamburger = (int *)malloc(sizeof(int)*n);
    for(int i = 0; i<n; i++){
        if(array[i] == 'H'){
            hamburger[i] = 1;
        } else {
            hamburger[i] = 0;
        }
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        if(array[i] == 'P'){
            int start = (i - k < 0) ? 0 : i - k;
            int end = (i + k >= n) ? n - 1 : i + k;

            for(int j = start; j <= end; j++){
                if(array[j] == 'H' && hamburger[j] == 1){
                    count++;
                    hamburger[j] = 0;
                    break;
                }
            }
        }
    }

    printf("%d\n", count);

    // 할당한 메모리 해제
    free(array);
    free(hamburger);

    return 0;
}
