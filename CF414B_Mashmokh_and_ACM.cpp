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

const int mod = 1e9 + 7;
const int N = 2000 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, k;
int f[N][N]; // 

int main(){
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        f[1][i] = 1;
    }
    // f[0][1] = 1;

    for (int i = 2; i <= k; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k * j <= n; k++){
                // if(j % k == 0)
                    f[i][j * k] = (f[i - 1][j] + f[i][j * k]) % mod;
            }
        }
    }

    // for (int i = 1; i <= k; i++){
    //     for (int j = 1; j <= n; j++){
    //         printf("%d %d %d\n", i, j, f[i][j]);
    //     }
    // }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = (ans + f[k][i]) % mod;
    }

    cout << ans;
}