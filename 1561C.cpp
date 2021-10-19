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

typedef pair<ll, ll> PII;

const int N = 1e5 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
PII a[N];

bool check(int id){
    // ll pow = a[id].y + a[id].x;
    ll pow = id;
    for (int i = 1; i <= n; i++){
        // if(i == id)
        //     continue;
        if(pow < a[i].x)
            return 0;
        else
            pow += a[i].y;
    }
    return 1;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            ll k;
            cin >> k;
            ll maxx = 0;
            for (ll j = 1; j <= k; j++){
                ll x;
                cin >> x;
                maxx = max(maxx, x - j + 1);
            }
            a[i].x = maxx + 1; // 至少的条件
            a[i].y = k; // 打完获得的能力

            // cout << a[i].x << " " << a[i].y << Endl;
        }

        sort(a + 1, a + 1 + n);
        // for (int i = 1; i <= n; i++){
        //     cout << a[i].x << " " << a[i].y << Endl;
        // }

        int l = a[1].x;
        int r = a[n].x;

        // if(check(l)){
        //     cout << a[l].x << endl;
        //     continue;
        // }

        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)){
                r = mid;
                // rp = a[mid].x;
            }
            else{
                l = mid + 1;
                // lp = a[mid].x;
            }
                
        }
        cout << l << endl;
        // cout << a[l].x << endl;
    }
}