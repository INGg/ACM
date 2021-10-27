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
int n;
int a[N];
int f[620];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 520;j++){
            if(f[j] < a[i]){
                f[j ^ a[i]] = min(f[j ^ a[i]], a[i]);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i <= 520; i++){
        if(f[i] != INF)
            cnt++;
    }
    cout << cnt << endl;
    for (int i = 0; i <= 520; i++){
        if(f[i] != INF){
            cout << i << ' ';
        }
    }
    cout << endl;
}

int main(){
    // cin >> T;
    T = 1;
    while(T--){
        solve();
    }
}