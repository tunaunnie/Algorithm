#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){

    char *words[11] = {"a", "e", "k", "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    std::string input;
    std::getline(std::cin, input);

    int length = input.length();
    int wordcount = 0;


    //temp는 각 알파벳의 시작 위치
    int temp = 0;
    int result = 0;

    //한글자 앞으로 갈때마다 단어 있나 확인
    for (temp; temp<length; ){

        if(temp>length) break;

        for(int j = 0; j<11; j++){

            if (j==0 || j==1|| j==2) {
                result = input.compare(temp, 1, words[j]);
                if(result == 0) { wordcount += 1; temp+=1;  break;} 
            }
            else if (j==5){
                result = input.compare(temp, 3, words[j]);
                if(result == 0) { wordcount += 1; temp+=3;  break;} 
            }
            else {
                result = input.compare(temp, 2, words[j]);
                if(result == 0) { wordcount += 1; temp+=2;  break;} 
            }
        }
        if(result != 0) { wordcount += 1; temp+=1;}

    }

    printf("%d", wordcount);


    return 0;
}


/*

ljes=njak

1. 한 글자씩 돌면서 찾아
  2. 모든 단어 순회하다가
     lj 찾았어 -> 카운트 증가하고 2부터
  2. 모든 단어 순회하다가

lj (뭐라도 일단) 찾았으면 -> 그 temp 더한 위치에서부터 다시 word[1]부터 찾기.
한 번 찾은 위치는 다시 돌아가지 않는 게 중요

a
e
k
c=
c-
dz=
d-
lj
nj
s=
z=


*/