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

const int N = 1e3 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n, m;
string a[N];
string b[N];

void solve(){
    map<string, int> mp;

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int j = 1; j <= m; j++){
        cin >> b[j];
    }

    for (int i = 1; i <= m; i++){
        string now = "";
        for (int j = 0; j < b[i].size(); j++){
            now += b[i][j];
            if(b[i][j] == '/'){
                mp[now] = 1;
            }
        }
    }

    int ans = n;

    for (int i = 1; i <= n; i++){
        string now = "";
        for (int j = 0; j < a[i].size(); j++){
            now += a[i][j];
            if(a[i][j] == '/'){
                if(mp[now] == 1)
                    continue;
                else if(mp[now] == 0)
                    mp[now] = 2;
                else if(mp[now] == 2){
                    ans--;
                    break;
                }
            }
        }
    }

    cout << ans << Endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}