#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int *top = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &top[i]);
    }

    stack<int> s;
    long long answer = 0;

    // 오른쪽에서 왼쪽으로 탐색
    for (int i = 0; i < n; i++) {
        // 스택에 있는 탑들이 현재 탑보다 낮으면 pop
        while (!s.empty() && s.top() <= top[i]) {
            s.pop();
        }

        // 스택에 남아 있는 탑들은 현재 탑보다 높은 탑들
        answer += s.size();

        // 현재 탑을 스택에 추가
        s.push(top[i]);
    }

    printf("%lld\n", answer);

    free(top);  // 메모리 해제
    return 0;
}
