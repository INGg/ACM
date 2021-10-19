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

const int N = 3e5 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
char c;
char s[N];

void solve(){
    cin >> n >> c;
    scanf("%s", s + 1);

    vector<int> v;
    int id = 0;
    for (int i = 1; i <= n; i++){
        if(s[i] != c){
            v.pb(i);
        }
        else{
            id = i;
        }
    }

    if(!v.size()){
        cout << 0 << endl;
    }
    else{
        if(id * 2 > n){
            cout << 1 << endl;
            cout << id << endl;
        }
        else{
            cout << 2 << endl;
            cout << n - 1 << ' ' << n << Endl;
        }
    }
    
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}