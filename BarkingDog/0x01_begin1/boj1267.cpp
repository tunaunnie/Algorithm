#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    int y_sum = 0;
    int m_sum = 0;

    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);

        y_sum += (arr[i]/30 + 1)*10;
        m_sum += (arr[i]/60 + 1)*15;
    }

    if (y_sum > m_sum){
        printf("M %d", m_sum);
    } else if (y_sum < m_sum) {
        printf("Y %d", y_sum);
    } else {
        printf("Y M %d", y_sum);
    }

    return  0;
}