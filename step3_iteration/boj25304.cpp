#include <stdio.h>

int main(){
    int total, num;
    int test = 0;
    scanf("%d %d", &total, &num);

    for (int i=0; i<num; i++){
        int price, tempnum;
        scanf("%d %d", &price, &tempnum);
        test += price * tempnum;
    }

    if (total == test){
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}