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
    int suma = 0;
    int sumb = 0;
    suma += c / 2 * 3;
    sumb += (c - c / 2) * 3;

    // cout << suma << ' ' << sumb << Endl;

    while(suma < sumb && b){
        // if(b){
            suma += 2;
            b--;
        // }
    }

    suma += b / 2 * 2;
    sumb += (b - b / 2) * 2;

    while(suma < sumb && a){
        // if(a){
            suma += 1;
            a--;
        // }
    }

    suma += a / 2;
    sumb += a - a / 2;

    cout << abs(sumb - suma) << Endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}