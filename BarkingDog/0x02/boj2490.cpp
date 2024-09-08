#include <stdio.h>

int main(){

    int num;

    for(int i = 0; i<3; i++){
        int count = 0;

        for(int j = 0; j<4; j++){
            num = 0;
            scanf("%d", &num);
            if(num == 1) count++;
        }
        switch(count){
            case 0 : {
                printf("D\n");
                break;
            };
            case 1 : {
                printf("C\n");
                break;
            };
            case 2 : {
                printf("B\n");
                break;
            };
            case 3 : {
                printf("A\n");
                break;
            };
            case 4 : {
                printf("E\n");
                break;
            };
        }
        }


    return 0;
}