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

const int N = 6000 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int h[N], ne[N], e[N], w[N], idx;
bool vis[N];
int f[N][N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u){
    f[u][1] = w[u];

    for (int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        dfs(j);
        f[u][1] += f[j][0];
        f[u][0] += max(f[j][0], f[j][1]);
    }
}

int main(){
    memset(h, -1, sizeof(h));

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        add(b, a);
        vis[a] = 1;
    }

    int start = 0;
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            start = i;
            break;
        }
            
    }

    dfs(start);

    cout << max(f[start][1], f[start][0]);
}