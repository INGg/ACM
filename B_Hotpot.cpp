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
int n, k, m;
int a[N];
int tmp[N];
int h[N];

struct nope
{
    // int x;
    vector<int> id;
    int num;
}val[N];

int v2[N];

void solve(){
    memset(tmp, 0, sizeof(tmp));
    memset(h, 0, sizeof(h));
    memset(val, 0, sizeof(val));
    memset(v2, 0, sizeof(v2));

    cin >> n >> k >> m;
    for (int i = 0; i < n; i++){
        scanf("%d", a + i);
    }

    // if(2 * n > m){
    //     for (int i = 0; i < m; i++){
    //         v2[a[i]]++;
    //         if(v2[a[i]] % 2 == 0){
    //             h[i]++;
    //         }
    //     }
        
    //     for (int i = 0; i < n - 1; i++){
    //         printf("%d ", h[i]);
    //     }
    //     printf("%d\n", h[n]);
    //     return;
    // }

    // 先考虑 2 * n >= m
    for (int i = 0; i < 2 * n; i++){
        val[a[i % n]].id.pb(i % n);
        val[a[i % n]].num ++;
        // cout << a[i % n] << " " << val[a[i % n]].num << endl;
        if(val[a[i % n]].num % 2 == 0){
            tmp[i % n]++;
        }
    }

    int x = m / (2 * n);

    for (int i = 0; i < n; i++){
        h[i] = tmp[i] * x;
    }
    
    for (int i = 0; i < m % (2 * n); i++){
        v2[a[i % n]]++;
        if(v2[a[i % n]] % 2 == 0){
            h[i % n]++;
        }
    }

    for (int i = 0; i < n - 1; i++){
        printf("%d ", h[i]);
    }
    printf("%d\n", h[n - 1]);
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}