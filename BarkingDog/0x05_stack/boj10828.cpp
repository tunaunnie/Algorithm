#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

// 명령에서 숫자 추출 함수 제거하고 바로 stoi() 사용
int main() {
    int n;
    stack<int> mystack;
    string command;

    // 숫자 입력 받고 개행 문자 처리
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        getline(cin, command);  // 명령어 입력 받기

        if (command == "pop") {
            if (!mystack.empty()) {
                printf("%d\n", mystack.top());
                mystack.pop();
            } else {
                printf("-1\n");
            }
        } else if (command == "size") {
            printf("%d\n", mystack.size());
        } else if (command == "empty") {
            printf("%d\n", mystack.empty() ? 1 : 0);
        } else if (command == "top") {
            if (!mystack.empty()) {
                printf("%d\n", mystack.top());
            } else {
                printf("-1\n");
            }
        } else if (command.substr(0, 4) == "push") {  
            int num = stoi(command.substr(5));  // 공백 이후 숫자 부분 추출
            mystack.push(num);
        }
    }

    return 0;
}
