#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

int main(){
    cin >> n >> m;
    int zheng = 0;
    int chang = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int t = min(i, j);
            zheng += t;
            chang += i * j - t; //i * j是以右下角为顶点的矩形个数
        }
    }
    cout << zheng << " " << chang;
    return 0;
}