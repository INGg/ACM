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

const int N = 10000 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m, val;
int v[N];
int w[N];
int fa[N];
int f[N];

void init(){
    for (int i = 1; i <= 10000; i++)
        fa[i] = i;
}

int query(int p){
    if(fa[p] == p)
        return p;
    else{
        int v = query(fa[p]);
        fa[p] = v;
        return v;
    }
}

void merge(int p1, int p2){
    int f1 = query(p1);
    int f2 = query(p2);

    if(f1 != f2){
        fa[f1] = f2;
        w[f2] += w[f1];
        v[f2] += v[f1];
    }
}

int main(){
    init();

    cin >> n >> m >> val;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    for (int i = 1; i <= n; i++){
        if(fa[i] == i){
            for (int j = val; j >= v[i]; j--){
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
    }

    cout << f[val];
}