#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    char arr[101];
    scanf("%s", arr); //왜 & 없음?
    
    int size = 0;
    while(arr[size] != '\0'){
        size++;
    }

    printf("%d", size);

    return 0;
}