#include <stdio.h>

int getlength(char *string){
    int length = 0;
    int i = 0;
    while(string[i++] != '\0'){
        length++;
    }

    return length;
}

int main(){

    char s[100];
    scanf("%s", &s);

    int length = getlength(s);
    int save[27]; //0부터 35번까지 (36개), 마지막은 null

    //배열 전부 -1로 초기화
    for(int i = 0; i<26; i++){
        save[i] = -1;
    }

    for(int ascii=97; ascii<123; ascii++){
        for(int i=0; i<length; i++){
            if((int)s[i] == ascii){
                if(save[ascii-97] == -1)
                    save[ascii-97] = i;
                else
                    break;
            }
        }
    }

    for(int i = 0; i<26; i++){
        printf("%d", save[i]);
        if(i != 26) printf(" ");
    }


    return 0;
}


/*

a부터 z까지 쭉 순회

단어 전체를 한바퀴 돌면서 
    해당 알파벳 있으면 
        && 지금 -1이면 save에 위치 저장

    해당 알파벳 있는데 
        && 지금 -1 아니면 다음 알파벳으로 넘어가기

1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1


*/