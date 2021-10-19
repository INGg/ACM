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

const int N = 1000 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
string s;
string ans;
map<string, int> m;

int v;

void dfs(string cur){
    if(ans.size())
        return;
    if(cur.size() == v){
        if(!m[cur])
            ans = cur;
        return;
    }
    for (int i = 'a'; i <= 'z'; i++)
        dfs(cur + (char)i);
}

void solve(){
    ans="";
    m.clear();
    s.clear();

    cin >> n;
    cin >> s;
    m[""] = 1;
    for (int i = 0; i < s.size(); i++){
        for (int j = 1; j <= s.size() - i; j++){ // 枚举长度，不是枚举终点
            m[s.substr(i, j)]++;
        }
    }

    for (int l = 1; l <= 5; l++){
        v = l;
        dfs("");
    }
    cout << ans << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}