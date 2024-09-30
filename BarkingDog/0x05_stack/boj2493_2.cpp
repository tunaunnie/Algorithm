#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int main()
{

    int n;
    scanf("%d", &n);

    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);

        // 비교할 원소가 없으면
        // 그냥 0 출력하고 지금 탑을 쌓음
        if (s.empty())
        {
            printf("0 ");
            pair<int, int> p = make_pair(i + 1, temp);
            s.push(p);
            continue;
        }

        // 앞전 탑보다 지금 쌓을 탑이 더 크다면
        // 앞에거는 지금 탑을 수신할 수 없음.
        // 앞전 탑을 pop 해야 함.
        if (s.top().second <= temp)
        {
            while (!s.empty() && s.top().second <= temp)
            {
                s.pop();
            }

            if (s.empty())
            {
                printf("0 ");
            }
            else
            {
                printf("%d ", s.top().first);
            }

            pair<int, int> p2 = make_pair(i + 1, temp);
            s.push(p2);
        }
        else
        { // 현재 마지막 top이 지금 내가 쌓을 탑보다 큼. 즉 수신 가능
            // 살리고 그대로 쌓음
            // 그리고 바로 앞 top을 출력해야지
            printf("%d ", s.top().first);
            pair<int, int> p = make_pair(i + 1, temp);
            s.push(p);
        }
    }

    return 0;
}