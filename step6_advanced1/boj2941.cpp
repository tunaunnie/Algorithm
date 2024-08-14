#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){

    char *words[12] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=", "a", "e", "k"};

    string str;
    getline(cin, str);

    int length = 0;
    while(str[length] != '\0'){
        length++;
    }

    int index = 0;
    int wordcount = 0;

        for(int i = 0; i<11; i++){
            printf("finding word %s ...\n", words[i]);

            //찾았으면 찾은 위치, 못찾았으면 -1
            int temp;
            temp = str.find(words[i], index);

            if(temp != -1) {
                printf("찾은 단어: %s, 찾은 위치: %d\n", words[i], temp);
                
                if(i==0 || i==1 || i==3 || i==6 || i==7 ){
                    wordcount += 1;
                    index += 2;
                }
                else if (i==2){
                    wordcount += 1;
                    index += 3;
                }
                else if (i==4 || i==5){
                    wordcount += 1;
                    index += 2;
                }
                else if (i==8 || i==9 || i==10){
                    wordcount += 1;
                    index += 1;
                }
            } 

            if(index >= length) break;
        }


   printf("wordcount: %d\n", wordcount);

    return 0;
}


/*

c=
c-
dz=
d-
lj
nj
s=
z=

*/