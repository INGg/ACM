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
const ll mod = 998244353;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

long long ksm(ll a,ll b,ll p) {long long ans=1;while (b) {if (b&1) ans=ans*a%p; a=a*a%p; b>>=1;} return ans;}

int T;
char s[N];
ll f[N][12];

void solve(){

    scanf("%s", s + 1);
    ll n = strlen(s + 1);

    for (ll i = 1; i <= n; i++){
        f[i][1] = ((f[i - 1][1] + (s[i] == 'n'))) % mod;
        f[i][2] = ((f[i - 1][2] + (s[i] == 'u') * f[i - 1][1])) % mod;
        f[i][3] = ((f[i - 1][3] + (s[i] == 'n') * f[i - 1][2])) % mod;
        f[i][4] = ((f[i - 1][4] + (s[i] == 'h') * f[i - 1][3])) % mod;
        f[i][5] = ((f[i - 1][5] + (s[i] == 'e') * f[i - 1][4])) % mod;
        f[i][6] = ((f[i - 1][6] + (s[i] == 'h') * f[i - 1][5])) % mod;
        f[i][7] = ((f[i - 1][7] + (s[i] == 'h') * f[i - 1][6])) % mod;
        f[i][8] = ((f[i - 1][8] + (s[i] == 'e') * f[i - 1][7])) % mod;
        f[i][9] = ((f[i - 1][9] + (s[i] == 'h') * f[i - 1][8])) % mod;
        // cout << i << " " << ans << endl;
    }

    ll suma = 0;
    ll ans = 0;
    for (ll i = n; i >= 1; i--){
        if(s[i] == 'a'){
            suma++;
            ans = (ans % mod + (f[i][9] * ksm(2, suma - 1, mod)) % mod) % mod;
        }
    }
    cout << ans % mod << Endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}