#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

        for (int i = 0; i<n-1; i++){
            for(int j = 0; j<n-i-1; j++){
                printf(" ");
            }
            for(int j = 0; j<2*i+1; j++){
                printf("*");
            }
            printf("\n");
        }

        for(int j = 0; j<2*n-1; j++){
            printf("*");
        }
        printf("\n");

        for (int i = 0; i<n-1; i++){
            for(int j = 0; j<i+1; j++){
                printf(" ");
            }
            for(int j = 2*n-3-2*i; j>0; j--){
                printf("*");
            }
            printf("\n");
        }


    return 0;
}


/*

n이 들어오면 

n-1줄 동안 정삼각형
1줄 동안 2n-1개 쭉 출력
n-1줄 동안 역삼각형


6이면 (총 11줄)


    *     5(1)5   -- 0
   ***    4(3)4   -- 1
  *****   3(5)3   -- 2
 *******  2(7)2   -- 3
 ******** 1(9)1   -- 4

***********  (11)    중간이 2n-1개


 *******  1(7)1
  *****   2(5)2
   ***    3(3)3
    *     4(1)4







*/