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

const int N = 4e5 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n, k;
ll a[N];

bool cmp(int a, int b){
    return b < a;
}

void solve(){
    cin >> n >> k;

    for (int i = 1; i <= k; i++){
        cin >> a[i];
    }

    sort(a + 1, a + 1 + k, cmp);

    // for (int i = 1; i <= k; i++){
    //     cout << a[i] << ' ';
    // }
    // cout << Endl;

    ll summ = 0;

    int res = 0;
    for (int i = 1; i <= k; i++){
        summ += (n - a[i]);
        // cout << summ << Endl;
        if(summ >= n){
            break;
        }
        res++;
    }
    cout << res << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}