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
// #include <deque>
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

void solve(){
    deque<int> q;

    cin >> n;
    for (int i = 1; i <= n; i++){

        int x;
        cin >> x;

        if(i == 1){
            q.push_back(x);
            continue;
        }

        int f = q.front();
        int b = q.back();

        if(x < f){
            q.push_front(x);
        }
        else
            q.push_back(x);
    }

    for(auto i : q){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}