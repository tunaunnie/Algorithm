#include <stdio.h>

int main(){

    char string[1000001];
    scanf("%s", &string);

    int alphabet[26];
    for (int i = 0; i<26; i++){
        alphabet[i] = 0;
    }

    int length = 0;
    while(string[length] != '\0'){
        length++;
    }

    for(int i = 0; i<length; i++){
        int temp = string[i];

        if(string[i] >= 65 && string[i] <= 90){
            //printf("alphabet[%d]: %d\n", temp-65, alphabet[temp-65]);
            alphabet[temp-65] += 1;
            //printf("alphabet[%d]: %d\n", temp-65, alphabet[temp-65]);
        }
        if(string[i] >= 97 && string[i] <= 122){
            alphabet[temp-97] += 1;
        }
    }

    int max = 0;
    for (int i = 0; i<26; i++){
        if(alphabet[i] > alphabet[max]) max = i;
    }

    for (int i = 0; i<26; i++){
        if(alphabet[i] == alphabet[max] && i != max) {
            printf("?");
            return 0;
        }
    }
    printf("%c", max+65);

    return 0;
}