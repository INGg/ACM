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

const int N = 2e5 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
int k;
ll a[N];
ll w[N];

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < k; i++){
        cin >> w[i];
    }

    ll ans = 0;
    sort(a, a + n);
    reverse(a, a + n);
    sort(w, w + k);

    for (int i = 0; i < k; i++){
        ans += a[i];
        if(w[i] == 1)
            ans += a[i];
        w[i]--;
    }

    int now = k;
    for (int i = 0; i < k; i++){
        if(!w[i])
            continue;
        ans += a[now + w[i] - 1];
        now += w[i];
    }

    cout << ans << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}