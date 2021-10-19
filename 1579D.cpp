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
PII a[N];
PII ans[N];

void solve(){
    priority_queue<PII> q;

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x;
        a[i].y = i;
        if(a[i].x)
            q.push(a[i]);
    }

    int cnt = 0;

    while(q.size() >= 2){
        // cout << q.size() << endl;
        auto x = q.top();
        q.pop();
        auto y = q.top();
        q.pop();

        ans[cnt].x = x.y;
        ans[cnt].y = y.y;
        cnt++;

        if(x.x > 1){
            x.x--;
            q.push(x);
        }
        if(y.x > 1){
            y.x--;
            q.push(y);
        }
    }

    cout << cnt << Endl;
    for (int i = 0; i < cnt; i++){
        cout << ans[i].x << " " << ans[i].y << endl;
    }
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}