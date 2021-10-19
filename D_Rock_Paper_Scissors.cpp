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

const int N = 10 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
ll b[N];
ll d[N];

void solve(){
    cin >> b[1] >> b[2] >> b[3];
    cin >> d[1] >> d[2] >> d[3];

    ll ans = 0;
    ll x;

    // ying
    ans += min(d[1], b[3]);
    x = min(d[1], b[3]);
    d[1] -= x;
    b[3] -= x;

    ans += min(d[2], b[1]);
    x = min(d[2], b[1]);
    d[2] -= x;
    b[1] -= x;

    ans += min(d[3], b[2]);
    x = min(d[3], b[2]);
    d[3] -= x;
    b[2] -= x;

    // ping
    x = min(d[1], b[1]);
    d[1] -= x;
    b[1] -= x;

    x = min(d[2], b[2]);
    d[2] -= x;
    b[2] -= x;

    x = min(d[3], b[3]);
    d[3] -= x;
    b[3] -= x;

    // shu
    ans -= b[1];
    ans -= b[2];
    ans -= b[3];

    cout << ans << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}