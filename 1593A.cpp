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
int a, b, c;

void solve(){
    cin >> a >> b >> c;
    int maxx = max(a, max(b, c));

    if(a == b && b == c && c == a){
        cout << 1 << ' ' << 1 << ' ' << 1 << endl;
        return;
    }
    if(a == maxx && b == maxx && c != maxx){
        cout << 1 << " " << 1 << ' ' << abs(c - maxx) + 1 << endl;
        return;
    }
    if(a == maxx && c == maxx && b != maxx){
        cout << 1 << " " << abs(b - maxx) + 1 << " 1" << endl;
        return;
    }
    if(c == maxx && b == maxx && a != maxx){
        cout << abs(a - maxx) + 1 << " " << 1 << ' ' << 1 << endl;
        return;
    }

    if(a != maxx){
        cout << abs(a - maxx) + 1 << " ";
    }
    else{
        cout << 0 << " ";
    }

    if(b != maxx){
        cout << abs(b - maxx) + 1 << " ";
    }
    else
        cout << 0 << " ";

    if(c != maxx){
        cout << abs(c - maxx) + 1 << " ";
    }
    else
        cout << 0 << " ";
    cout << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}