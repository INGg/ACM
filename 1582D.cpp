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
int a[N];
int b[N];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    if(!(n & 1)){
        for (int i = 1; i <= n; i += 2){
            cout << -1 * a[i + 1] << ' ' << a[i] << ' ';
        }
        cout << endl;
    }
    else{
        for (int i = 1; i <= n - 3; i += 2){
            cout << -1 * a[i + 1] << ' ' << a[i] << ' ';
        }
        int x = a[n - 2];
        int y = a[n - 1];
        int z = a[n];

        if(x + z != 0){
            printf("%d %d %d\n", y, -(x + z), y);
        }
        else if(x + y != 0){
            printf("%d %d %d\n", z, z, -(x + y));
        }
        else{
            printf("%d %d %d\n", -(z + y), x, x);
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}