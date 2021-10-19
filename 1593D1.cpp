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

void solve(){
    vector<int> s1, s2;

    int x;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        s1.pb(x);
    }

    int flag = 0;
    for(auto i : s1){
        if(i != x){
            flag = 1;
            break;
        }
    }

    if(!flag){
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < s1.size(); i++){
        for (int j = i + 1; j < s1.size(); j++){
            s2.pb(abs(s1[i] - s1[j]));
        }
    }

    int g = s2[0];
    for(auto i : s2){
        g = __gcd(i, g);
    }

    cout << g << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}