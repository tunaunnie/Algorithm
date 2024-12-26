#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool DESC(int a, int b){
    return a>b;
}

int main(){

    vector<int> v;
    int n;
    int element;

    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &element);
        v.push_back(element);
    }

    sort(v.begin(), v.end(), DESC);

    for(int i = 0; i<n; i++){
        printf("%d\n", v[i]);
    }

    return 0;
}