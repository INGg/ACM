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

const int N = 100 + 10;
const int mod = 1e6 + 7;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
int a[N];
int f[N][N];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    f[0][0] = 1; // 类似背包
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            for (int k = 0; k <= min(j, a[i]); k++){
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
            }
        }
    }

    cout << f[n][m];
}