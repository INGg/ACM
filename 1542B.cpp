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
int n, a, b;

void solve(){
    cin >> n >> a >> b;

    ll t = 1;
    if((n - t) % b == 0){
        cout << "Yes" << endl;
        return;
    }
    while(t <= n && a > 1){
        if((n - t) % b == 0){
            cout << "Yes" << Endl;
            return;
        }
        t *= a;
    }
    cout << "No" << Endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}