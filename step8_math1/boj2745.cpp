#include <stdio.h>
#include <iostream>
#include <string>

int mult(int num, int rep){
    int result = 1;

    for(int i = 0; i<rep; i++){
        result *= num;
    }

    return result;
}

int main(){

    std::string input;
    int form; // ex) 16진법

    std::cin >> input >> form;

    int length = input.length();
    long long result = 0;

    for (int i = 0; i<length; i++){
        //현재 보고 있는 글자가 숫자라면 (48 ~ 57)
        if(input[length-(i+1)] >= 48 && input[length-(i+1)] <= 57){
            //printf("계산하는 중 : %d * %d^%d\n", input[length-(i+1)]-48, form, i );
            int temp = mult(form, i);
            int temp2 = (input[length-(i+1)]-48) * temp ;
            //printf("temp1: %d, temp2: %d\n", temp, temp2);
            result += temp2;

        }
        //현재 보고 있는 글자가 알파벳 대문자라면 (65 ~ 90)
        else{
            //printf("계산하는 중 : %d * %d^%d\n", input[length-(i+1)]-55, form, i );
            int temp = mult(form, i);
            int temp2 = (input[length-(i+1)]-55) * temp ;
            //printf("temp1: %d, temp2: %d\n", temp, temp2);
            result += temp2;
        }
    }

    printf("%d", result);

    return 0;
}

/*

length: 2
1, 9, ''
0, 1, length

length-1 글자는 * form^0
length-2 글자는 * form^1
length-3 글자는 * form^2
...
0번째 글자 (length-length)는 * form^(length-1)

A13C90 들어오면

int i = 0 ~ length까지
하나씩 앞으로 가면서 * B의 거듭제곱을 누적해서 합하기


*/