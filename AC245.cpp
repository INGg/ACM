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
#define lson u<<1,l,mid
#define rson u<<1|1,mid+1,r

using namespace std;

typedef pair<int, int> PII;

const int N = 500000 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct node{
    int l, r;
    int ls, rs; // 前后缀和
    int ts; // 这个区间的最大字段和
    int s; // 区间和
} tr[N << 2];

int n, m;
int w[N];

void pushup(node &u, node &l, node &r){
    u.ls = max(l.ls, l.s + r.ls);
    u.rs = max(r.rs, r.s + l.rs);
    u.ts = max(max(l.ts, r.ts), l.rs + r.ls);
    u.s = l.s + r.s;
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    if(l == r)
        tr[u] = {l, r, w[r], w[r], w[r], w[r]};
    else{
        tr[u].l = l;
        tr[u].r = r;
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushup(u);
    }
}

void modify(int u, int x, int v){
    if(tr[u].l == x && tr[u].r == x)
        tr[u] = {x, x, v, v, v, v};
    else{
        int mid = (tr[u].l + tr[u].r) >> 1;
        if(x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

node query(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r)
        return tr[u];
    else{
        int mid = (tr[u].l + tr[u].r) >> 1;
        if(mid < l)
            return query(u << 1 | 1, l, r);
        else if(mid >= r) // 这个一定要给r
            return query(u << 1, l, r);
        else{
            node res;
            node left = query(u << 1, l, r);
            node right = query(u << 1 | 1, l, r);
            pushup(res, left, right);
            return res;
        }
    }
}

int main(){
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }

    build(1, 1, n);

    while(m --){
        int k, x, y;
        cin >> k >> x >> y;
        if(k == 1){
            if(x > y)
                swap(x, y);
            cout << query(1, x, y).ts << endl;
        }
        else{
            modify(1, x, y);
        }
    }
}