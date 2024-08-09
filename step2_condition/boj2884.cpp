#include <stdio.h>

int main(){

    int hour, min;
    scanf("%d %d", &hour, &min);

    if (min >= 45){
        printf("%d %d", hour, min-45);
    } else if (min < 45 && hour != 0){
        printf("%d %d", hour-1, min+60-45);
    } else {
        printf("23 %d", min+60-45);
    }

    return 0;
}