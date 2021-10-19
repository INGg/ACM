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
    map<char, int> m;

    for (int i = 0; i < s.size(); i++){
        m[(char)s[i]]++;
    }

    int a = m['A'];
    int b = m['B'];
    int c = m['C'];

    if(b - a - c == 0)
        cout << "YES" << Endl;
    else
        cout << "NO" << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}