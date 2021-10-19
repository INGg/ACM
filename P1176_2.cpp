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

const int N = 1000 + 10;
const int mod = 100003;

int n, m;
bool st[N][N];
int f[N][N];

int main(){
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        st[x][y] = 1;
    }

    f[1][1] = 1;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(!st[i - 1][j])
                f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
            if(!st[i][j - 1])
                f[i][j] = (f[i][j - 1] + f[i][j]) % mod;
        }
    }

    cout << f[n][n];

    return 0;
}