#include <iostream>
#include <cstdio>

using namespace std;

int num[10];
int n, m;

int main(){
    cin >> m >> n;
    for (int i = m; i <= n; i++){
        int x = i;
        while(x){
            num[x % 10]++;
            x /= 10;
        }
    }
    for (int i = 0; i <= 9; i++){
        cout << num[i] << " ";
    }
    return 0;
}