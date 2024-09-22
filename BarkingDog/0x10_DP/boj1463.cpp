#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        arr[i] = 0;
    }
    int *candidate = (int *)malloc(sizeof(int) * 3);
    for(int i = 0; i<3; i++){
        candidate[i] = -1;
    }

    //1은 0번 걸린다.
    arr[0] = 0;


    for(int i = 2; i<=n; i++){

        int candidate_num = 0;
        int candidate_index = 0;

        if(i % 3 == 0){
            candidate_num++;
            candidate[candidate_index++] = arr[i/3 - 1] + 1;
        }
        if (i % 2 == 0){
            candidate_num++;
            candidate[candidate_index++] = arr[i/2 - 1] + 1;
        }
        candidate_num++;
        candidate[candidate_index++] = arr[i-2] + 1;

        int min = candidate[0];
        for(int i = 0; i<candidate_index; i++){
            if(min >= candidate[i]){
                min = candidate[i];
            }
        }

        arr[i-1] = min;

    }

    printf("%d", arr[n-1]);

    return 0;
}