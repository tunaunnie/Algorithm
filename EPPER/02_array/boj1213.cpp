#include <stdio.h>
#include <stdlib.h>


int main(){

    char array[100];
    scanf("%s", array);

    int length = 0;
    for(int i = 0; array[i] != '\0'; i++){
        length++;
    }

    //개수 전부 0개로 초기화
    int count[26] = {0};

    //개수 각각 초기화
    for(int i = 0; i<length; i++){
        count[array[i]-65]++;
    }
    

  // 문자열 정렬
    for(int i = 0; i < length - 1; i++){
        for(int j = i + 1; j < length; j++){
            if(array[i] > array[j]){
                char temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    int temp_count = 0;
    int odd_alphabet;

    for(int i = 0; i<26; i++){
        if(count[i] % 2 != 0){
            temp_count++;
            odd_alphabet = i;
        }
    }

    if(length % 2 ==0){

        //개수가 홀수개인 알파벳이 하나라도 있으면 불가능
        if(temp_count != 0){
            printf("I'm Sorry Hansoo");
            return 0;
        }
        for(int i = 0; i<26; i++){
            if(count[i] == 0) continue;
            for(int j = 0; j<count[i]/2; j++){
                printf("%c", i + 'A');
            }
        }
        for(int i = 25; i>=0; i--){
            if(count[i] == 0) continue;
            for(int j = 0; j<count[i]/2; j++){
                printf("%c", i + 'A');
            }
        }
        

    } else{

        //개수가 홀수개인 알파벳이 하나만 있어야 함
        if(temp_count != 1){
            printf("I'm Sorry Hansoo");
            return 0;
        }
        for(int i = 0; i<26; i++){
            if(count[i] == 0) continue;
            for(int j = 0; j<count[i]/2; j++){
                printf("%c", i + 'A');
            }
        }
        printf("%c", odd_alphabet+'A');
        for(int i = 25; i>=0; i--){
            if(count[i] == 0) continue;
            for(int j = 0; j<count[i]/2; j++){
                printf("%c", i + 'A');
            }
        }
        

    }

    return 0;
}