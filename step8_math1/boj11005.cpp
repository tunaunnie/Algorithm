#include <stdio.h>
#include <stdlib.h>

int main(){

    long long input;
    int form;
    char *result = NULL;
    int length = 0;

    scanf("%lld %d", &input, &form);
    long long temp = input;

    while(temp > 0){
        result = (char *)realloc(result, (length+2) * sizeof(char));

        if(temp % form < 10){ //int형 숫자를 -> 문자형 숫자로 바꿔서 넣기
            result[length] = (char)((temp % form)+48);
        }
        else{                //10 이상의 숫자를 -> 대문자로 바꿔서 넣기
            result[length] = (char)((temp%form)+55);
        }
        length++;
        result[length] = '\0';
        temp /= form;
    }

    for(int i = length-1; i>=0; i--){
        printf("%c", result[i]);
    }

    return 0;
}

/*

200이면 (길이 3)
나머지가 form보다 작아질 때까지 계속 나누고, 나머지 계속 차곡차곡 저장
 if (나머지 > 9) 대문자로 수정해서 저장

*/