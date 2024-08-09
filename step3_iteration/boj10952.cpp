#include <stdio.h>

int main(){

 int a[100];
 int b[100];
 int temp[100];
int i = 0;

while(true){
    scanf("%d %d", &a[i], &b[i]);
    temp[i] = a[i] + b[i];

    if(a[i]==0 && b[i]==0) break;
    i++;
}

for (int j=0; ; j++){
    if(a[j]==0 && b[j]==0) break;
    printf("%d\n", temp[j]);
}

    return 0;
}