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

const int N = 2000 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
int q;
int a[N];

void solve(){
    vector<int> b[N];

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int num = 0; num <= n; num++){
        map<int, int> m;

        if(!num){
            for (int i = 0; i < n; i++){
                b[0].pb(a[i]);
            }
            // cout << "num : " << num << endl;
            // for (int i = 0; i < n; i++){
            //     cout << b[num][i] << ' ';
            // }
            // cout << endl;
            continue;
        }
        for(auto i : b[num - 1]){
            // cout << i << ' ';
            // b[num].push_back(i);
            m[i]++;
        }
        // cout << endl;
        // cout << endl;
        for (int i = 0; i < n; i++){
            b[num].pb(m[b[num - 1][i]]);
        }

        // cout << "num : " << num << endl;
        // for (int i = 0; i < n; i++){
        //     cout << b[num][i] << ' ';
        // }
        // cout << endl;
    }

    cin >> q;
    while(q--){
        int x, k;
        scanf("%d%d", &x, &k);

        if(k < n){
            cout << b[k][x - 1] << endl;
        }
        else{
            cout << b[n][x - 1] << endl;
        }
    }

    // for (int i = 0; i <= n; i++){
    //     b[i].clear();
    // }
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}