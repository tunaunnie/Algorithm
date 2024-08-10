#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n;
    scanf("%d", &n);

    float *score = (float *)malloc(sizeof(float)*n);
    float *newscore = (float *)malloc(sizeof(float)*n);
    float sum = 0;

    for(int i=0; i<n; i++){
        scanf("%f", &score[i]);
    }

    float max = score[0];

    for(int i=0; i<n; i++){
        if(score[i] > max) max = score[i];
    }

    for(int i=0; i<n; i++){
        newscore[i] = score[i]/max*100;
        sum+=newscore[i];
    }

    printf("%f", sum/n);

    return 0;
}