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
int backup[N];
int st[N]; // 编号没用过

void solve(){
    int ans = 0;
    memset(b, 0, sizeof(b));
    memset(st, 0, sizeof(st));
    memset(backup, 0, sizeof(backup));

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if(!st[a[i]]){
            b[i] = a[i];
            st[a[i]] = 1;
            ans++;
        }
    }

    memcpy(backup, b, sizeof(b));

    vector<int> v; // 没人送的人
    for (int i = 1; i <= n; i++){
        if(!st[i])
            v.pb(i);
    }

    // zheng xu
    reverse(v.begin(), v.end());
    for (int i = 1, j = 0; i <= n; i++){
        if(!b[i]){
            b[i] = v[j++];
        }
    }

    // sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 1, j = 0; i <= n; i++){
        if(!backup[i]){
            backup[i] = v[j++];
        }
    }

    int cnt_z = 0;
    int cnt_r = 0;
    for (int i = 1; i <= n; i++){
        if(b[i] == i)
            cnt_z++;
    }
    for (int i = 1; i <= n; i++){
        if(backup[i] == i)
            cnt_r++;
    }

    if(cnt_z > cnt_r){
        for (int i = 1; i <= n; i++){
            b[i] = backup[i];
        }
    }

    int id = 0;
    for (int i = 1; i <= n; i++){
        if(b[i] == i){
            id = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++){
        if(b[i] == a[id] && i != id){
            swap(b[i], b[id]);
        }
    }

    cout << ans << Endl;
    for (int i = 1; i <= n; i++){
        cout << b[i] << ' ';
    }
    cout << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}