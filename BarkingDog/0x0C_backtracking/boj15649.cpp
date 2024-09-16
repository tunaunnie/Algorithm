#include <stdio.h>
#include <stdlib.h>

int n, m;
int *arr;
int *check;

// k개 채워진 상태, 다음에 채워야 할 건 arr[k]
void func(int k, int *arr, int *check) {
    // arr에 m개를 다 채웠으면 출력하고 return
    if(k == m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    // 1부터 n까지, 다음에 채울 수 있는 숫자를 탐색
    for(int i = 0; i < n; i++) {
        if(check[i] == 0) {
            arr[k] = i + 1;  // 1부터 n까지를 사용하기 위해 +1
            check[i] = 1;
            func(k + 1, arr, check);
            check[i] = 0;
        }
    }
}

int main() {
    // 입력 받기
    scanf("%d %d", &n, &m);

    // 동적 메모리 할당
    arr = (int *)malloc(sizeof(int) * m);
    check = (int *)malloc(sizeof(int) * n);

    // check 배열 초기화
    for(int i = 0; i < n; i++) {
        check[i] = 0;
    }

    // 0개가 정해진 상태서부터 시작
    func(0, arr, check);

    // 동적 메모리 해제
    free(arr);
    free(check);

    return 0;
}
