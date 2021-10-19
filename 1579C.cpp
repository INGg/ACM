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
int n, m, k;
char g[30][30];
int b[30][30];

void check(int i, int j){
    int d = 0;
    int r = i;
    int c = j;
    while(1){
        if(d > n || r < 1 || c + d > m || c - d <= 0)
            break;
        // cout << g[r - d][c + d] << " " << g[r - d][c - d] << Endl;
        if(g[r - d][c + d] != '*' || g[r - d][c - d] != '*')
            break;

        d++;
    }
    d--;

    if(d >= k){
        for (int a = 0; a <= d; a++){
            b[r - a][c + a] = b[r - a][c - a] = 1;
        }
    }
}

void solve(){
    memset(b, 0, sizeof(b));
    // memset(g, 0, sizeof(g));

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        scanf("%s", g[i] + 1);
    }

    for (int i = n; i >= 1; i--){
        for (int j = 1; j <= m; j++){
            if(g[i][j] != '*')
                continue;

            check(i, j);
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(g[i][j] == '*' && b[i][j] != 1){
                cout << "NO" << endl;
                return;
            }                
        }
    }

    cout << "YES" << Endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}