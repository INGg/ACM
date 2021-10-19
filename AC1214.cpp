#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;

const int MOD = 100000007;

int n;
ll s, a, b;
int vis[1000 + 10];
int ans = 0;
set<int> ss;

void work(){
    int num = n;
    ll summ = 0;
    for (int i = 1; i <= n; i++){
        if(vis[i])
            summ += (--num) * a;
        else
            summ += (--num) * b;
    }
    if((s - summ) / n * n == (s - summ))
        ans = (ans + 1) % MOD, ss.insert((s - summ) / n);
}

void dfs(int num){
    if(num == n + 1){
        work();
        return;
    }

    vis[num] = 1;
    dfs(num + 1);
    vis[num] = 0;
    dfs(num + 1);
    vis[num] = 0;
}

int main(){
    cin >> n >> s >> a >> b;
    b *= -1;
    dfs(1);
    cout << ans / 2 % MOD;
    return 0;
}