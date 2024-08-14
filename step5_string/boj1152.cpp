#include <stdio.h>
#include <iostream>

int getlength(char *str){
    int length = 0;
    int i = 0;
    while(str[i++] != '\0'){
        length++;
    }

    return length;
}

int main(){

    char string[1000002];
    std::cin.getline(string, 1000002);
    
    int length = getlength(string);
    int blankcount = 0;

    for(int i = 0; i<length; i++){
        if(string[i] == ' ' ){
            if(i != 0 && i != length-1){
                blankcount++;
            }
        }
    }

    if (blankcount == 0) {
        if(length == 0) printf("%d", 0); // ''인 경우
        else if(string[0] == string[length-1] && length == 1 && string[0] == ' ') printf("%d", 0);
        else if(string[0] == string[length-1] && length == 2 && string[0] == ' ') printf("%d", 0);  
        else printf("1"); // 'a', ' a', 'a ', ' a ' 처리
    }
    else printf("%d", blankcount+1);

    return 0;
}


/*

1 + blank의 개수 (이때 blank는 맨앞 맨뒤 제외)


blankcount 0인 경우

'' -> 0개 
'a' -> 1개 
' a' -> 1개
' a ' -> 1개
'a ' -> 
' ' -> 0개

' 'the curious case of benjamin button' '


*/