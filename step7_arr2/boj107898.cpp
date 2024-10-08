#include <stdio.h>
#include <stdlib.h>

int getlength(char *string){
    int length = 0;
    
    while(string[length] != '\0'){
        length++;
    }
    return length;
}

int main(){

    char *words[5]; //단어가 5개
    int lengths[5]; //길이가 5개 (0~4)

    for(int i = 0; i<5; i++){
        words[i] = (char *)malloc(sizeof(char)*20);
        scanf("%s", words[i]);
        lengths[i] = getlength(words[i]);
        
    }

    int max_length = lengths[0];

    for (int i = 0; i<5; i++){
        if(lengths[i] > max_length)
            max_length = lengths[i];
    }
    //printf("max_length: %d\n", max_length);
    
    for(int i = 0; i<max_length; i++){
        for(int j = 0; j<5; j++){
            if (i < lengths[j])
                printf("%c", words[j][i]);
        }
    }

    return 0;
}


/*

if (j >= lengths[i]) 

word[0] =          (길이 0)
word[1] = 123      (길이 3)
word[2] = def12    (길이 5)
word[3] = 01234    (길이 5)
word[4] = fghddfdfddfi      (길이 )

00 10 20 30 40
01 11 21 31 41
02 12 22 32 42
* * 23 33 43

Aa0FfBb1GgCc2HhDd3IiEe4Jj
Aa0FfBb1GgCc2HhDd3IiEe4Jj

Aa0aPAf985Bz1EhCz2W3D1gkD6x
Aa0aPAf985Bz1EhCz2W3D1gkD6x

*/