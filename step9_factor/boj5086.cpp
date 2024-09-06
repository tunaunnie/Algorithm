#include <stdio.h>

int main(){

    int first, second;

    while(true){

        scanf("%d %d", &first, &second);

        if(first == 0 && second == 0) return 0;

        if(second % first == 0){
            printf("factor\n");
        }else if(first % second == 0){
            printf("multiple\n");
        }else{
            printf("neither\n");
        }
    }

    return 0;
}