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

const int N = 100000 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

#define root 1,2*k,1
#define lson l,m,rt<<1 //这个线段树把左区间分为l到m，右区间是m+1到r
#define rson m+1,r,rt<<1|1
#define int ll

int k, n;
int a[N << 1];
int z[N * 8];

void update(int rt){
    z[rt] = min(z[rt << 1], z[rt << 1 | 1]);
    // z[rt] = min(z[rt * 2], z[rt * 2 + 1]);
}

void modify(int l, int r, int rt, int p, int v){ //编号为rt的节点，区间是l到r，修改位置是p，要给p这个位置加上v
    if(l == r){
        z[rt] = v;
        return;
    }

    int m = (l + r) >> 1;
    if(p <= m) //小于一半就意味着在左边
        modify(lson, p, v);
    else
        modify(rson, p, v);
    update(rt);
}

int query(int l, int r, int rt, int nowl, int nowr){ // 编号为rt的节点，区间是l到r；我们现在询问的区间是nowl到nowr 
    // 前面l==r本质上从当前位置一直走到树的最下面，这样就不符合在线段树下某段区间包含在要求的区间内就不往下查询的特性了

    if(nowl <= l && r <= nowr)
        return z[rt];

    /*
    三种情况：
    只在右边
    只在左边
    左右都有交集
    */
    int m = (l + r) >> 1;
    if(nowl <= m){ // 一定和左区间有交集
        // 左右都有交集
        if(m < nowr) // 是否跨过中点
            return min(query(lson, nowl, nowr), query(rson, nowl, nowr));
        else
            return query(lson, nowl, nowr);
    }
    else 
        return query(rson, nowl, nowr);
}

signed main(){
    cin >> k >> n;

    ll res = 0;

    for (int i = 0; i < n; i++){
        int s, p;
        cin >> s >> p;

        int l = i % k + 1;
        int r = i % k + k;

        if(query(root, l, r) > s){ // 所有区间都不行，就直接抛弃了
            continue;
        }

        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (query(root, l, mid) <= s)
                r = mid; // check()判断mid是否满足性质
            else
                l = mid + 1;
        }

        modify(root, l, s + p);
        modify(root, (l + k - 1) % (2 * k) + 1, s + p);

        res = max(res, ++a[(l - 1) % k + 1]);
    }

    // cout << res << endl;

    bool flag = 0;

    // for (int i = 1; i <= k; i++){
    //     cout << i << " : " << a[i] << endl;
    // }

    for (int i = 1; i <= k; i++){
        if (a[i] == res){
            if (flag)
                cout << " " << i - 1;
            else{
                flag = 1;
                cout << i - 1;
            }
        }
    }
}