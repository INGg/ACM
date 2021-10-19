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
int s[N];

bool cmp(int a, int b) {
    return a > b;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }

    int ans = 999999;
    for (int i = 1; i <= n; i++){
        if(s[i] > s[n] - s[i]){
            ans = min(ans, i);
        }
    }

    cout << ans << endl;
}

int main(){
    // cin >> T;
    T = 1;
    while(T--){
        solve();
    }
}