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
string s;

void solve(){
    cin >> s;

    int cnt = 0;
    s = '1' + s;

    for (int i = 0; i < s.size() - 1; i++)
        if(s[i] == '1' && s[i + 1] == '0')
            cnt++;

    cout << min(cnt, 2) << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}