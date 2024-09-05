#include <stdio.h>
#include <stack>
#include <stdlib.h>

using namespace std;

int main(){

    stack<int> stack;

    int k;
    scanf("%d", &k);
    int *array = (int *)malloc(sizeof(int) * (k+1));
    for(int i = 0; i<k; i++){
        scanf("%d", &array[i]);
    }

    for(int i = 0; i<k; i++){
        if(array[i] != 0){
            stack.push(array[i]);
        } else {
            stack.pop();
        }
    }
    
    int sum = 0;
    int size = stack.size();
    for(int i = 0; i<size; i++){
        sum += stack.top();
        stack.pop();
    }

    printf("%d", sum);
    
    return 0;
}