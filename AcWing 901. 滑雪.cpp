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

const int N = 300 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
int h[N][N];
int f[N][N];

int dfs(int x, int y){
    if(f[x][y] != -1)
        return f[x][y];
    f[x][y] = 1;
    for (int i = 0; i < 4; i++){
        int a = x + dx[i];
        int b = y + dy[i];
        if(a < 1 || a > n || b < 1 || b > m || h[x][y] <= h[a][b])
            continue;
        f[x][y] = max(dfs(a, b) + 1, f[x][y]);
    }
    return f[x][y];
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> h[i][j];
        }
    }

    memset(f, -1, sizeof(f));
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
}