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
int x;
int a[N];
int b[N];

void solve(){
    cin >> n >> x;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        // a[i].id = i;
    }

    memcpy(b, a, sizeof(a));

    sort(b + 1, b + 1 + n);

    int flag = 0;
    for (int i = n - x + 1; i <= x; i++){
        if(a[i] != b[i]){
            flag = 1;
        }
    }
    if(flag == 0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}