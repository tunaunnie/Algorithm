#include <stdio.h>

int main(){

  int n, count;
  scanf("%d", &n);

  if(n%4 == 0){
    count = n/4;
  } else{
    count = n/4 + 1;
  }

  for(int i = 0; i<count; i++){
    printf("long ");
  }
  printf("int");

    return 0;
}

/* 
long은 4바이트까지
longlong은 8바이트까지.

딱떨어지면 ==> 그 몫까지.
딱 안떨어지고 나머지 있으면 ==> 몫 + 1만큼 반복

*/