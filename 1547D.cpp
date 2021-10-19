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
int a[N];
int b[N];
int c[N];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
    }

    b[1] = 0;
    c[1] = a[1];
    for (int i = 2; i <= n; i++){
        c[i] = c[i - 1] | a[i];
        b[i] = c[i] ^ a[i];
    }

    for (int i = 1; i <= n; i++){
        cout << b[i] << " ";
    }
    cout << Endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}