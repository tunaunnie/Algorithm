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

    char string[1000000];
    std::cin.getline(string, 1000000);
    
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
        if(length == 0) printf("%d", blankcount);
        else if (string[0] == ' ') printf("%d", blankcount);
        else printf("1");
    }
    else printf("%d", blankcount+1);

    return 0;
}


/*

1 + blank의 개수 (이때 blank는 맨앞 맨뒤 제외)


blankcount 0인 경우

'' -> 0개 (1개로 나옴)
a -> 1개 (1개로 나옴)
' ' -> 0개 (1개로 나옴)

' 'the curious case of benjamin button' '


*/