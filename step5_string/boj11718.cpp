#include <stdio.h>
#include <iostream>
using namespace std;

int main(){

    char string[102];

    while(true){
        std::cin.getline(string, 102);

        if(string[0] == '\n' || string[0] == ' ' || string[0] == NULL) break;

        printf("%s\n", string);
        
    }

    return 0;
}


/*

while문으로 계속 쭉 이어서 저장받기 ... + 개행문자
그러다가 buffer 초과하면 쭉 그대로 출력하기?

*/