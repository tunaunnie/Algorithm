#include <stdio.h>
#include <stdlib.h>

int getlength(char *arr){
    int length = 0;
    while(arr[length] != '\0'){
        length++;
    }

    return length;
}

int main(){

    char arr[60];
    scanf("%s", arr);

    int alphabet[26] = {0};
    int length = getlength(arr);

    //각 알파벳의 개수 세기
    for(int i = 0; i<length; i++){
        alphabet[arr[i]-'A']++;
    }

    int odd_count = 0;
    int odd_index;

    //홀수번 사용된 알파벳 개수, index 구하기
    for(int i = 0; i<26; i++){
        if(alphabet[i] % 2 == 1){
            odd_count++;
            odd_index = i;
        }
    }

    //전체 글자가 홀수개인 경우
    if(length % 2 == 1){

        if(odd_count != 1){
            printf("I'm Sorry Hansoo");
            return 0;
        }

        //사전 순서대로 절반만큼 출력
        for(int i = 0; i<26; i++){

            if(alphabet[i] == 0){
                continue;
            }

            for(int j = 0; j<alphabet[i]/2; j++){
                printf("%c", i+'A');
            }

        }
        //홀수개인 애 중간에 한 번 출력
        printf("%c", odd_index+'A');
        //사전 반대 순서대로 절반만큼 출력
        for(int i = 25; i>=0; i--){

            if(alphabet[i] == 0){
                continue;
            }
            for(int j = 0; j<alphabet[i]/2; j++){
                printf("%c", i+'A');
            }
        }

    } else { //전체 글자가 짝수개인 경우

        if(odd_count != 0){
            printf("I'm Sorry Hansoo");
            return 0;
        }

        //사전 순서대로 절반만큼 출력
        for(int i = 0; i<26; i++){

            if(alphabet[i] == 0){
                continue;
            }

            for(int j = 0; j<alphabet[i]/2; j++){
                printf("%c", i+'A');
            }

        }
        //사전 반대 순서대로 절반만큼 출력
        for(int i = 25; i>=0; i--){

            if(alphabet[i] == 0){
                continue;
            }
            for(int j = 0; j<alphabet[i]/2; j++){
                printf("%c", i+'A');
            }
        }


    }
    
    return 0;
}