#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int f[1000 + 10][1000 + 10]; //f[i][j] 为即将撞i架飞机，衰变年龄为j的粒子最终能产生几个粒子。
int n, k;

int dp(int i, int j){
    if(i == 0 || j == 1) // i==0就是没得撞了，j==1就是符合题意不会产生新的粒子了
        return 1;
    if(f[i][j] != -1)
        return f[i][j];
    f[i][j] = dp(i - 1, j) + dp(n - i, j - 1);
    f[i][j] %= MOD;
    return f[i][j];
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        memset(f, -1, sizeof(f));
        cout << dp(n, k) << endl;
    }
    return 0;
}