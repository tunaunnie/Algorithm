#include <stdio.h>

int main(){

    int score;
    scanf("%d", &score);

    if (score/10 >= 9){
        printf("A");
    } else if (score/10 >= 8){
        printf("B");
    } else if (score/10 >= 7){
        printf("C");
    } else if (score/10 >= 6){
        printf("D");
    } else {
        printf("F");
    }

    return 0;
}