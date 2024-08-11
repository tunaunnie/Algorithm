#include <iostream>
#include <string>
using namespace std;

int main(){
    string arr;
    getline(cin, arr);

    int num;
    scanf("%d", &num);

    cout << arr[num-1];

}