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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int a[N];
int f[N][N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[i][i] = a[i];
    }

    for (int j = 2; j <= n; j++){
        for (int i = j - 1; i >= 1; i--){

            f[i][j] = abs(a[i] - a[j]) * (j - i + 1);

            for (int k = i; k < j; k++){
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
            }
        }
    }

    cout << f[1][n];

    return 0;
}