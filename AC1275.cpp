#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define root 1,m,1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ll long long

using namespace std;

const int N = 2e5 + 10;

int n, m, p;
int tr[N << 2];

void update(int rt){
    tr[rt] = max(tr[rt << 1], tr[rt << 1 | 1]);
}

void build(int l, int r, int rt, int v){
    if(l == r){
        tr[rt] = v;
        return;
    }

    int mid = (l + r) >> 1;

    build(lson, v);
    build(rson, v);

    update(rt);
}

void modify(int l, int r, int rt, int p, int v){
    if(l == r){
        tr[rt] = v;
        return;
    }

    int mid = (l + r) >> 1;
    if(p <= mid)
        modify(lson, p, v);
    else
        modify(rson, p, v);

    update(rt);
}

int query(int l, int r, int rt, int nowl, int nowr){ // 编号为rt的节点，区间是l到r；我们现在询问的区间是nowl到nowr 
    // 前面l==r本质上从当前位置一直走到树的最下面，这样就不符合在线段树下某段区间包含在要求的区间内就不往下查询的特性了

    if(nowl <= l &&r <= nowr)
        return tr[rt];

    /*
    三种情况：
    只在右边
    只在左边
    左右都有交集
    */
    int mid = (l + r) >> 1;
    if(nowl <= mid){ // 一定和左区间有交集
        // 左右都有交集
        if(mid < nowr) // 是否跨过中点
            return max(query(lson, nowl, nowr), query(rson, nowl, nowr));
        else
            return query(lson, nowl, nowr);
    }
    else 
        return query(rson, nowl, nowr);
}

int last;

void debug(){
    for (int i = 1; i <= m; i++){
        cout << tr[i] << " ";
    }
    cout << endl;
}

int main(){
    cin >> m >> p;
    for (int _ = 1; _ <= m; _++){
        char op[2];
        scanf("%s", op);

        if(op[0] == 'Q'){
            int L;
            cin >> L;
            last = query(root, n - L + 1, n);
            cout << last << endl;
        }
        else{
            int t;
            cin >> t;
            modify(root, n + 1, (ll)(t + last) % p);
            n++;
            // debug();
        }
    }
}