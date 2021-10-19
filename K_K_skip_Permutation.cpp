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
#define int ll
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
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, k;
int st[N];

signed main(){
    cin >> n >> k;

    if(k > n || k == 1){
        for (int i = 1; i < n; i++){
            cout << i << ' ';
        }
        cout << n;
        return 0;
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++){
        if(!st[i]){
            for (int j = 0; i + j * k <= n; j++){
                ans.pb(i + j * k);
                st[i + j * k] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if(!st[i]){
            ans.pb(i);
        }
    }

    for (int i = 0; i < ans.size() - 1; i++){
        printf("%d ", ans[i]);
    }
    cout << ans[(int)(ans.size() - 1)];
}