#include <stdio.h>

int main(){

    char string[101];
    scanf("%s", &string);

    int length = 0;
    while(string[length] != '\0'){
        length++;
    }

    for(int i = 0; i<length; i++){
        if (string[i] != string[length-i-1]){
            printf("0");
            return 0;
        }
    }

    printf("1");


    return 0;
}
