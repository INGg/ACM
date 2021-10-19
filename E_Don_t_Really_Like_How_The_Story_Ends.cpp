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

const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n, m;
int cnt, nxt;
bool st[N];
vector<int> g[N * 2];

void dfs(int u){
    if(u == n + 1)
        return;
    for(auto v : g[u]){
        if(v < nxt)
            continue;
        while(v >= nxt){
            if(v == nxt){
                nxt++;
                dfs(nxt - 1);
            }
            else{
                nxt++;
                cnt++;
                dfs(nxt - 1);
            }
        }
    }
}

void solve(){
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[v].pb(u);
        g[u].pb(v);
    }

    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());

    g[1].pb(n + 1); // (为了方便让1 11和n + 1 n+1n+1相连,因为需要遍历所有点)
    cnt = 0;
    nxt = 2;

    dfs(1);
    cout << cnt << Endl;

    for (int i = 1; i <= n; i++){
        g[i].clear();
    }

}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}