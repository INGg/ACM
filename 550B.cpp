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

const int N = 1e6 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, l, r, x;
ll c[N];
int ans;

bool vis[100]; //bool数组存好，还省空间

void dfs(int num, int n){ 
    if(num > n){
        ll summ = 0;
        ll maxx = 0;
        ll minn = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++){
            if(vis[i] == 1){
                summ += c[i];
                maxx = max(maxx, c[i]);
                minn = min(minn, c[i]);
            }
        }
        if(summ >= l && summ <= r && maxx - minn >= x)
            ans++;
        // printf("\");
        return;
    }

    vis[num] = 1; //选他
    dfs(num + 1, n);
    vis[num] = 0; //恢复现场加不选他
    dfs(num + 1, n);
    vis[num] = 0; //恢复现场
}

int main(){
    cin >> n >> l >> r >> x;

    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }

    dfs(1, n);

    cout << ans;
}