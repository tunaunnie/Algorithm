#include <stdio.h>

int main(){

    int alphabet[26];
    char word[100];

    scanf("%s", word);
    for(int i = 0; i<26; i++){
        alphabet[i] = 0;
    }

    for(int i = 0; word[i] != '\0'; i++){
        alphabet[word[i]-'a']++;
    } 

    for(int i = 0; i<26; i++){
        printf("%d ", alphabet[i]);
    }

    return 0;
}