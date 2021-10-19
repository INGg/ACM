#include <iostream>

using namespace std;

int n; //我们数组一共有n个数

#define root 1,n,1
#define lson l,m,rt<<1 //这个线段树把左区间分为l到m，右区间是m+1到r
#define rson m+1,r,rt<<1|1

int z[500000 * 4];

void update(int rt){
    z[rt] = min(z[rt << 1], z[rt << 1 | 1]);
    // z[rt] = min(z[rt * 2], z[rt * 2 + 1]);
}

void build(int l, int r, int rt){ //建树；线段树编号为rt的节点，对应的区间是从l到r
    if(l == r){
        cin >> z[rt];
        return;
    }

    int m = (l + r) >> 1;
    build(lson); //这里认为左儿子的编号是自己乘2
    build(rson); //右儿子的编号是自己乘2+1
    update(rt);
}

void modify(int l, int r, int rt, int p, int v){ //编号为rt的节点，区间是l到r，修改位置是p，要给p这个位置加上v
    if(l == r){
        z[p] += v;
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

    if(nowl <= l &&r <= nowr)
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

int main(){
    cin >> n;
    build(root);

    int m; //假设有m个操作
    cin >> m;
    for (int i = 1; i <= m; i++){
        string s;
        cin >> s;
        if(s == "xiugai"){
            int p, v;
            cin >> p >> v;
            modify(root, p, v); //从root开始修改p，v值
        }
        if(s == "xunwen"){
            int l, r;
            cin >> l >> r;
            cout << query(root, l, r) << endl;
        }
    }

        return 0;
}