#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int *arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int max1 = arr[0];
    int min1 = arr[0];

    for(int i = 0; i<n; i++){
        if(arr[i] >= max1){
            max1 = arr[i];
        }

        if(arr[i] <= min1){
            min1 = arr[i];
        }

    }

    //최대 차이로 일단 초기화.
    int min2 = max1-min1;

    //배열을 정렬하면 중첩for문 안 쓸 수 있음
    //오름차순으로 정렬됨
    sort(arr, arr+n);

    int i = 0, j = 0;
    int diff;

    while(j < n) {
        diff = arr[j] - arr[i];

        if(diff >= m){
            min2 = min(min2, diff);
            i++;
            if(i > j){
                j = i;
            }
        } else {
            j++;
        }
    }

    printf("%d", min2);


    return 0;
}