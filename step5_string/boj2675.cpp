#include <stdio.h>
#include <stdlib.h>

int getlength(char *str){
    int length = 0;
    int i = 0;
    
    while( str[i] != '\0'){
        length++;
        i++;
    }

    return length;
}

int main(){

    int num;
    scanf("%d", &num);

    int loop[1000];
    char *str[1000];

    for (int i = 0; i<num; i++){
        str[i] = (char *)malloc(sizeof(char) * 20);
        scanf("%d %s", &loop[i], str[i]);
    }

    for(int i = 0; i<num; i++){
        int length = getlength(str[i]);
        int rep = loop[i];

        for(int j = 0; j<length; j++){
            for(int k = 0; k<rep; k++){
                printf("%c", str[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < num; i++) {
        free(str[i]);
    }


    return 0;
}


/*

loop[0] : 첫번째 문장의 반복 횟수
str[0] : 첫번째 문장

loop[1] : 두번째 문장의 반복 횟수
str[1] : 두번째 문장

첫번째 문장을 순회하면서, 한 알파벳 당 loop[0]만큼 출력하고 넘어가
첫번째 문장 끝났으면 두번째 문장으로



*/