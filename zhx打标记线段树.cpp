#include <iostream>

using namespace std;

#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int z[500000 * 4];
int col[500000 * 4]; //标记操作

void update(int rt){
    z[rt] = z[rt << 1] + z[rt << 1 | 1];
}

void build(int l, int r, int rt){
    if(l == r){
        cin >> z[rt];
        return;
    }

    build(lson);
    build(rson);
    update(rt);
} 

void color(int l, int r, int rt, int v){ // 给节点打上标记
    //打上标记后，区间和会变成原来的v *(r - l + 1)
    z[rt] = z[rt] + (r - l + 1) * v;
    col[rt] += v; // 合并标记
}

void push_col(int l, int r, int rt){ //把l和r的标记下放，放到左右儿子上
    
    if(col[rt] != 0){
        int m = (l + r) >> 1;
        color(lson, col[rt]); //告诉儿子们打上标记
        color(rson, col[rt]);
        col[rt] = 0; // 清除标记
    }
}

void modify(int l, int r, int rt, int nowl, int nowr, int v){ //表示从nowl到nowr全部加上v
    if(nowl <= l && nowr >= r){
        color(l, r, rt, v);
        return;
    }
    int m = (l + r) >> 1;
    push_col(l, r, rt);
    if(nowl <= m)
        modify(lson, nowl, nowr);
    if(m < nowr)
        modify(rson, nowl, nowr);
    update(rt);
}

int query(int l, int r, int rt, int nowl, int nowr){
    if(nowl <= l && nowr >= r){
        return z[rt];
    }

    int m = (l + r) >> 1;
    push_col(l, r, rt); //标记下放
    //三种情况
    if(nowl <= m){
        if(nowr > m){
            return query(lson, nowl, nowr) + query(rson, nowl, nowr);
        }
        else
            return query(lson, nowl, nowr);
    }
    else{
        return query(rson, nowl, nowr);
    }
}

int main(){
    
}