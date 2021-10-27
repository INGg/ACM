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

ll a, b, c, d;

void solve(){
    ll ans = 0;
    
    // a~b   c~d
    // 2018*n l1~
    ll num_2018_x = (b / 2018) - ((a - 1) / 2018);
    ans += num_2018_x * (d - c + 1);

    // a~b  c~d
    // l2~ 2018*m
    ll num_2018_y = (d / 2018) - ((c - 1) / 2018);
    ans += num_2018_y * (b - a + 1);

    // 1009*(2n-1) 2n
    ll num_1009_x = (b / 1009) - ((a - 1) / 1009) - num_2018_x;
    ll num_2_y = (d / 2) - ((c - 1) / 2) - num_2018_y;
    ans += num_1009_x * num_2_y;

    // 2m 1009*(2m-1)
    ll num_1009_y = (d / 1009) - ((c - 1) / 1009) - num_2018_y;
    ll num_2_x = (b / 2) - ((a - 1) / 2) - num_2018_x;
    ans += num_1009_y * num_2_x;

    ans -= (num_2018_x * num_2018_y);

    cout << ans << endl;
}

int main(){

    // cin >> T;
    while(cin >> a >> b >> c >> d){
        solve();
    }
}