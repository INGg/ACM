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

const int N = 10000 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int W, n, m;
int v[N];
int w[N];
int f[N];

int main(){
    cin >> W >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    int ans = 1e9;
    for (int i = 1; i <= n; i++){
        for (int j = m; j >= v[i]; j--){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    for (int i = 1; i <= m; i++){
        if(f[i] >= W){
            cout << m - i << Endl;
            return 0;
        }
    }
    cout << "Impossible";
}