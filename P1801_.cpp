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
int n, m;
int a[N];
int b[N];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    sort(b, b + m);

    priority_queue<int> ql;
    priority_queue<int, vector<int>, greater<int>> qs;

    int i = 0;
    int j = 0;
    while(i < n || j < m){
        while(j < m && i == b[j]){
            cout << qs.top() << endl;

            ql.push(qs.top());
            qs.pop();

            j++;
        }
        int x = a[i];
        if(ql.empty() || x >= qs.top()){
            qs.push(x);
        }
        else{
            ql.push(x);
            qs.push(ql.top());
            ql.pop();
        }
        i++;
    }
}

int main(){
    // cin >> T;
    T = 1;
    while(T--){
        solve();
    }
}