#include <stdio.h>
#include <stdlib.h>
#include <string>

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    char *arr = (char *)malloc(sizeof(char) * n);
    scanf("%s", arr);
    
    int answer = 0;

    for(int i = 0; i<n; i++){

        if(arr[i] == 'H'){
            continue;
        } else if (arr[i] == '.'){
            continue;
        } else { // 사람인 경우

            int range1 = i-k;
            int range2 = i+k;

            for(int j = range1; j<=range2; j++){

                //범위 벗어나면 탐색하지 않고 넘어감
                if(j <0 || n<=j){
                    continue;
                } else { //범위 내인 경우
                    //안 먹은 햄버거 발견
                    if(arr[j] == 'H'){
                        answer++;
                        arr[j] = '.';
                        break;
                    }
                }

            }
        }

    }


    printf("%d", answer);

    return 0;
}