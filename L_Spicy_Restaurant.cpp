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
int n, m, q;
int f[N][110]; // f[i][j]表示离i最近的属性值j的距离
int h[N * 2], e[N * 2], ne[N * 2], idx;
int w[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool st[N];
void bfs(int val){
    queue<int> q;
    memset(st, 0, sizeof(st));

    for (int i = 1; i <= n; i++){
        if(w[i] == val){
            f[i][val] = 0;
            q.push(i);
            st[i] = 1;
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (int i = h[u]; i != -1; i = ne[i]){
            int v = e[i];
            if(st[v])
                continue;
            f[v][val] = f[u][val] + 1;
            q.push(v);
            st[v] = 1;
        }
    }
}

void solve(){
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++){
        scanf("%d", w + i);
    }

    memset(h, -1, sizeof(h));

    for (int i = 1; i <= m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a != b){
            add(a, b);
            add(b, a);
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 100; j++){
            f[i][j] = INF;
        }
    }

    for (int i = 1; i <= 100; i++){
        bfs(i);
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 100; j++){
            f[i][j] = min(f[i][j], f[i][j - 1]);
        }
    }

    while(q--){
        int p, a;
        scanf("%d%d", &p, &a);
        if(f[p][a] == INF){
            cout << -1 << endl;
        }
        else
            cout << f[p][a] << endl;
    }
}

int main(){
    // cin >> T;
    T = 1;
    while(T--){
        solve();
    }
}