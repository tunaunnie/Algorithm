#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main()
{

    int num;
    scanf("%d", &num);
    int answer = 0;

    int temp;

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &temp);

        int flag = 0;

        if (temp == 1){
            flag = 1;
        }
        else if (temp == 2){
            flag = 0;
        }
        else{
            for (int j = 2; j*j <= temp; j++)
            {
                // 돌다가 한 번이라도 약수가 나오면 flag = 1
                if (temp % j == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0)
        {
            answer++;
        }
    }

    printf("%d", answer);

    return 0;
}