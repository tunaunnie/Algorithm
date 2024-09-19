#include <stdio.h>
#include <stdlib.h>

int n, m;
int *check;
int *arr;

void func(int k)
{

    if (k == m){

        int max = arr[m - 1];

        for (int i = 0; i < m; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0)
        {
            if (k > 0)
            {
                if (arr[k - 1] < i+1)
                {
                    check[i] = 1;
                    arr[k] = i + 1;
                    func(k + 1);
                    check[i] = 0;
                }
            }
            else if (k == 0)
            {
                check[i] = 1;
                arr[k] = i + 1;
                func(k + 1);
                check[i] = 0;
            }
        }
    }
}

int main()
{

    scanf("%d %d", &n, &m);
    check = (int *)malloc(sizeof(int) * n);
    arr = (int *)malloc(sizeof(int) * m);

    for (int i = 0; i < n; i++)
    {
        check[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        arr[i] = 0;
    }

    func(0);

    return 0;
}