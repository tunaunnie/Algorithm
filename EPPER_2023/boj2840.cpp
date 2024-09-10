#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, k;
    scanf("%d %d", &n, &k);
    
    char *wheel = (char *)malloc(sizeof(char) * n);
    for(int i = 0; i<n; i++){
        wheel[i] = '-';
    }

    int jump;
    char c;
    int pos = 0;
    int flag = 0;

    for(int i = 0; i<k; i++){
        scanf("%d %c", &jump, &c);

        pos = pos + jump;
        if(pos >= n) pos %= n;
        
        if(wheel[pos] == '-') wheel[pos] = c;
        else if(wheel[pos] != '-' && wheel[pos] != c){
            flag = 1;
        }
        
    }

    // printf("완성된 바퀴:\n");
    // for(int i = 0; i<n; i++){
    //     printf("%c ", wheel[i]);
    // }
    // printf("\n");

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i != j && wheel[i] == wheel[j] && wheel[i] != '-'){
                flag = 1;
            }
        }
    }
        
    if(flag == 1){
        printf("!");
        return 0;
    }

    int index2 = pos;

    for(int i = 0; i<n; i++){

        int temp;

        if(index2 - i >= 0){
            temp = index2-i;
        }else{
            temp = (index2-i) + n;
        }
        
        if(wheel[temp] == '-'){
            printf("?");
        } else {
            printf("%c", wheel[temp]);
        }
    }

    return 0;
}