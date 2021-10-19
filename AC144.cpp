#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 100000 + 10;

int n;
int e[2 * N], ne[2 * N], h[2 * N], w[2 * N], idx;
int d[2 * N];
int vis[2 * N];

void add(int u, int v, int ww){
    e[idx] = v;
    ne[idx] = h[u];
    w[idx] = ww;
    h[u] = idx++;
}

void dfs(int u){
    vis[u] = 1;
    
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!vis[j]){
            d[j] = w[i] ^ d[u];
            dfs(j);
        }
    }
}

int son[31 * N][2], tidx;
// 每个数最多有31位，一个有N个数，一共需要31 * N个节点

void insert(int x){
    int p = 0;
    for (int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(!son[p][u])
            son[p][u] = ++tidx;
        p = son[p][u];
    }
}

int query(int x){
    int p = 0;
    int res = 0; // 记录路径上的数是什么
    for (int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(son[p][!u]){ // 如果另一个方向存在，肯定走使答案变大的那个方向
            p = son[p][!u];
            res = (res << 1) + !u;
        } 
        else{
            p = son[p][u];
            res = (res << 1) + u;
        }       
    }
    return res;
}

int main(){
    memset(h, -1, sizeof(h));
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    
    dfs(0);
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        insert(d[i]);
        ans = max(ans, d[i] ^ query(d[i]));
    }
    cout << ans;
    return 0;
}