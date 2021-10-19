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
int a[N];
int st[N][4];

void solve(){
    int minn = mod;
    int idx = 0;

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < minn){
            minn = a[i];
            idx = i;
        }
    }

    // cout << minn << " " << idx << endl;

    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if(i == idx)
            continue;
        st[cnt][0] = i;
        st[cnt][1] = idx;
        st[cnt][2] = minn + abs(i - idx);
        st[cnt][3] = minn;
        cnt++;
    }

    cout << cnt << Endl;
    for (int i = 0; i < cnt; i++){
        for (int j = 0; j < 4; j++){
            cout << st[i][j] << " ";
        }
        cout << Endl;
    }
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}