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
int k;

void solve(){
    cin >> k;
    if(k > 12){
        cout << 0 << endl;
    }
    else{
        if(k == 1){
            cout << 0 << endl;
        }
        if(k == 2){
            cout << 1 << endl;
        }
        if(k == 3){
            cout << 1 << endl;
        }
        if(k == 4){
            cout << 2 << endl;
        }
        if(k == 5){
            cout << 2 << endl;
        }
        if(k == 6){
            cout << 3 << endl;
        }
        if(k == 7){
            cout << 3 << endl;
        }
        if(k == 8){
            cout << 3 << endl;
        }
        if(k == 9){
            cout << 2 << endl;
        }
        if(k == 10){
            cout << 2 << endl;
        }
        if(k == 11){
            cout << 1 << endl;
        }
        if(k == 12){
            cout << 1 << endl;
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}