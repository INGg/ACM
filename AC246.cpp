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
#define int ll
#define ull unsigned long long
#define re return
#define pb push_back
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 500000 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
ll a[N];

struct node{
    int l, r;
    ll summ;
    ll g;
} tr[N << 2];

void pushup(node &u, node &l, node &r){
    u.summ = l.summ + r.summ;
    u.g = __gcd(l.g, r.g);
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    if(l == r){
        ll g = a[l] - a[l - 1];
        tr[u] = {l, r, g, g};
    }
    else{
        tr[u].l = l;
        tr[u].r = r;

        int mid = (l + r) >> 1;

        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, ll v){
    if (tr[u].l == x && tr[u].r == x){
        ll b =  tr[u].summ + v;
        tr[u] = {x, x, b, b};
    }
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
    if(l <= tr[u].l && tr[u].r <= r){
        return tr[u];
    }
    else{
        int mid = (tr[u].l + tr[u].r) >> 1;

        if(mid >= r){
            return query(u << 1, l, r);
        }
        else if(mid < l){
            return query(u << 1 | 1, l, r);
        }
        else{
            node right = query(u << 1 | 1, l, r);
            node left = query(u << 1, l, r);
            node res;
            pushup(res, left, right);
            return res;
        }
    }
}

signed main(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        scanf("%lld", a + i);
    }

    build(1, 1, n);

    int l, r, d;
    char op[2];
    while(m--){
        scanf("%s", op);

        scanf("%lld%lld", &l, &r);

        if(op[0] == 'C'){
            scanf("%lld", &d)
            modify(1, l, d);
            if(r + 1 <= n)
                modify(1, r + 1, -d);
        }
        else{
            node left = query(1, 1, l);
            node right = {0, 0, 0, 0};
            if(l + 1 <= r)
                right = query(1, l + 1, r);
            printf("%lld\n", abs(__gcd(left.summ, right.g)));
        }
    }
}