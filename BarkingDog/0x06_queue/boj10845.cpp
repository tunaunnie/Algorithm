#include <stdio.h>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    char command[20];

    int type;
    int num;

    queue<int> q;

    for(int i = 0; i<n; i++){
        scanf(" %[^\n]", command);

        if(strncmp(command, "push", 4) == 0){

            num = atoi(command + 5);
            q.push(num);

        } else if (strncmp(command, "pop", 3) == 0){
            if(q.empty()){
                printf("-1\n");
            }else {
                printf("%d\n", q.front());
                q.pop();
            }
        } else if (strncmp(command, "size", 4) == 0){
            printf("%d\n", q.size());

        } else if (strncmp(command, "empty", 5) == 0){
            if(q.empty()){
                printf("1\n");
            }else {
                printf("0\n");
            }
        } else if (strncmp(command, "front", 5) == 0){
            if(q.empty()){
                printf("-1\n");
            }else {
                printf("%d\n", q.front());
            }
            
        } else if (strncmp(command, "back", 4) == 0){
            if(q.empty()){
                printf("-1\n");
            }else {
                printf("%d\n", q.back());
            }
        
        }

    }



    return 0;
}