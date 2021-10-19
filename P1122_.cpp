#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define re return
#define pb push_back
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 16000 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int h[N], e[N * 2], ne[N * 2], w[N], idx;
int f[N];

void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u, int fa){
    f[u] = w[u];

    for (int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(j == fa)
            continue;
        dfs(j, u);
        f[u] = max(f[u], f[j] + f[u]); // 选以j为节点的，不选以j为节点的
    }
}

int main(){

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }

    memset(h, -1, sizeof(h));
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs(1, -1);

    int ans = -2147483647;
    for (int i = 1; i <= n; i++){
        ans = max(ans, f[i]);
    }
    cout << ans;
}