#include <stdio.h>

int main(){
    int count;
    scanf("%d", &count);

    int sum = 0;

    char arr[100];
    scanf("%s", &arr);

    for(int i = 0; i<count; i++){
        sum += arr[i] - 48;
    }

    printf("%d", sum);


    return 0;
}