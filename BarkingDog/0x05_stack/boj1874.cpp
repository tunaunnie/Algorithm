#include <stdio.h>
#include <stack>
#include <stdlib.h>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);


    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    stack<int> mystack;
    stack<int> answer;

    int pos = 0;
    int flag = 0;
    int i = 1;
    
    while(true){

        if(pos >= n){
            break;
        }

        if(mystack.empty()){
            mystack.push(i);
            answer.push(1);
            i++;
        } else if (arr[pos] == mystack.top()){
            mystack.pop();
            pos++;
            answer.push(0);
        } else if (arr[pos] != mystack.top()){
            if( i <= n){
                mystack.push(i);
                answer.push(1);
                i++;
            } else {
                flag = 1;
                break;
            }

        }
    }

    if(flag == 1){
        printf("NO");
        return 0;
    } else {
        int size = answer.size();
        int *real_answer = (int *)malloc(sizeof(int) * size);

        for(int i = 0; i<size; i++){
            real_answer[size-i-1] = answer.top();
            answer.pop();
        }

        for(int i = 0; i<size; i++){
            if(real_answer[i] == 0){
                printf("-\n");
            } else if (real_answer[i] == 1){
                printf("+\n");
            }
        }

    }

    return 0;
}