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
int n, m;
int a[N];
int b[N];
int c[N];
bool st[N];

void solve(){
    memset(st, 0, sizeof(st));

    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        cin >> a[i] >> b[i] >> c[i];
        st[b[i]] = 1;
    }

    int x;
    for (int i = 1; i <= n; i++){
        if(!st[i]){
            x = i;
            break;
        }
    }

    for (int i = 1; i <= n; i++){
        if(i != x){
            cout << i << ' ' << x << endl;
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}