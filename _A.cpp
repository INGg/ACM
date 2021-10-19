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
ll x;

void solve(){
    cin >> x;
    ll l = 0;
    ll r = 1e8;
    while(l < r){
        ll mid = l + r >> 1;
        if (mid * (mid + 1) / 2 >= x) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    ll z = l * (l + 1) / 2 - x;
    if(z == 1)
        l++;
    cout << l << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}