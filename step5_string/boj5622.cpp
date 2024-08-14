#include <stdio.h>

int main(){

    char word[16];
    scanf("%s", &word);

    int num[16];
    int i = 0;
    int time = 0;

    for(i; word[i]!= NULL; i++){
        if(word[i] == 'A' || word[i] == 'B' || word[i] == 'C'){
            num[i] = 2; }
        else if (word[i] == 'D' || word[i] == 'E' || word[i] == 'F'){
            num[i] = 3; }
        else if (word[i] == 'G' || word[i] == 'H' || word[i] == 'I'){
            num[i] = 4; }
        else if (word[i] == 'J' || word[i] == 'K' || word[i] == 'L'){
            num[i] = 5; }
        else if (word[i] == 'M' || word[i] == 'N' || word[i] == 'O'){
            num[i] = 6; }
        else if (word[i] == 'P' || word[i] == 'Q' || word[i] == 'R'|| word[i] == 'S'){
            num[i] = 7; }
        else if (word[i] == 'T' || word[i] == 'U' || word[i] == 'V'){
            num[i] = 8; }
        else if (word[i] == 'W' || word[i] == 'X' || word[i] == 'Y'|| word[i] == 'Z'){
            num[i] = 9; }
        else {
            num[i] = 0;
        }
    }
    num[i] = '\0';

    for(int j = 0; j<i; j++){
        time += (num[j]+1);
        //printf("num[%d]: %d\n", j, num[j]);
    }

    printf("%d", time);

    return 0;
}


/*


1: 2초
2: 3초
...
9: 10초
0: 11초

단어가 주어지면 -> 한글자씩 해당 숫자 구하기
숫자 구했으면 -> 걸리는 시간 계산하기

A: 65 -> 0  => 몫0 + 1
B: 66 -> 1 => 몫0 + 1
C: 67 -> 2 => 몫0 + 1

Z: 90 -> 25 => 몫8 +1 = 9

*/