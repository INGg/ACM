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
    cin >> n;
    // if(n == 3 || n == 5 || n == 7)
    //     cout << "NO" << endl;

    if(n % 4 != 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
        
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}