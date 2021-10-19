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
#define int ll
#define int_32 int
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

int T;
int n, k, x;
int p[N];
int t[N];
int h[N];
int s[N];

void debug(){
    for (int i = 1; i <= n; i++){
        cout << h[i] << ' ';
    }
    cout << endl;
}

void solve(){
    cin >> n >> k >> x >> p[0];

    for (int i = 1; i <= n; i++){
        scanf("%lld", s + i);
    }
    for (int i = 1; i <= k; i++){
        scanf("%lld", t + i);
    }
    for (int i = 1; i <= k; i++){
        scanf("%lld", p + i);
    }

    for (int i = 1; i <= n; i++){
        h[i] = x / s[i];
        if(x / s[i] * s[i] != x)
            h[i]++;
    }
    sort(h + 1, h + 1 + n);

    // debug();

    ll ans = 0;
    for (int i = 0; i <= k; i++){
        // cout << "p[i] - t[i] : " << p[i] - t[i] << endl;
        // cout << upper_bound(h + 1, h + 1 + n, p[i] - t[i]) - h << endl;

        ll l = 1;
        ll r = n;
        while(l < r){
            ll mid = (l + r + 1) >> 1;
            if(h[mid] <= p[i] - t[i])
                l = mid;
            else
                r = mid - 1;
        }

        // cout << "p[i] - t[i] : " << p[i] - t[i] << endl;

        
        if(l == 1 && h[l] > p[i] - t[i]){
            l--;
        }
        // cout << l << endl;

        ans = max(ans, l);
    }

    cout << ans << Endl;
}

signed main(){
    // cin >> T;
    T = 1;
    while(T--){
        solve();
    }
}