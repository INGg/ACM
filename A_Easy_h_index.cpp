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

ll n;
ll a[N];

void solve(){
    for (int i = 0; i <= n; i++){
        scanf("%lld", a + i);
    }

    ll summ = 0;
    for (ll i = n; i >= 0; i--){
        summ += a[i];
        if(summ >= i){
            cout << i << endl;
            return;
        }
    }

}

int main(){
    while(cin >> n){
        solve();
    }
}