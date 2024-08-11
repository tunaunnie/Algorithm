#include <stdio.h>
#include <iostream>

int getlength(char *string){

    int length = 0;
    int i = 0;

    while(string[i] != '\0'){
        i++;
    }

  return i;
}

int main(){

    int num;
    scanf("%d", &num);

    char *first = (char *)malloc(sizeof(char) * num);
    char *end = (char *)malloc(sizeof(char) * num);

    for(int i = 0; i<num; i++){
        char arr[1000];
        scanf("%s", arr);

        first[i] = arr[0];
        int length = getlength(arr);
        end[i] = arr[length-1];
    }

    for(int i = 0; i<num; i++){
        printf("%c%c\n", first[i], end[i]);
    }

    return 0;
}