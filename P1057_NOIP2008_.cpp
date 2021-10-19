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

const int N = 50 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
int f[N][N]; // f[i][j]传了i次，传到j个人的方案数

int main(){
    cin >> n >> m;
    f[0][1] = 1;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if(j == 1)
                f[i][j] = f[i - 1][n] + f[i - 1][j + 1];
            else if(j == n)
                f[i][j] = f[i - 1][n - 1] + f[i - 1][1];
            else
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
        }
    }
    cout << f[m][1];
}