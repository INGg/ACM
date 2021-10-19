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
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n, m;
set<int> s;
string g[N];

void solve(){
    bool flag = 1;
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    auto tmp = s.upper_bound(x);
    if(tmp != s.end()){
        if(*tmp <= y){
            flag = 0;
        }
    }

    if(flag)
        cout << "YES" << Endl;
    else
        cout << "NO" << endl;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> g[i];
    }

    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            if(i > 0 && j > 0){
                if(g[i][j - 1] == 'X' && g[i - 1][j] == 'X'){
                    s.insert(j);
                    break;
                }
            }
        }
    }

    cin >> T;
    while(T--){
        solve();
    }
}