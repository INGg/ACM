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
ll a[N];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    ll cnt_1 = 0;
    for (int i = 1; i <= n; i++){
        if(a[i] == 1){
            cnt_1++;
        }
        if(a[i] > 1)
            break;
    }

    ll cnt_0 = 0;
    for (int i = 1; i <= n; i++){
        if(a[i] == 0){
            cnt_0++;
        }
        if(a[i] > 0)
            break;
    }

    if(!cnt_1){
        cout << 0 << Endl;
        return;
    }

    cout << cnt_1 * ((ll)1 << cnt_0) << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}