// Problem: 有依赖的背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/10/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-28 12:48:24

#include <iostream>
#include <vector>

using namespace std;

const int N = 110;

int n, m;
vector<int> g[N]; // 邻接矩阵存图
int f[N][N]; // 以u为根节点，容量不超过j的最大价值
int v[N];
int w[N];

void dfs(int u){
    for(int i = v[u]; i <= m; i++) f[u][i] = w[u];
    
    for(int i = 0; i < g[u].size(); i++){
        int y = g[u][i];
        dfs(y);
        for(int j = m; j >= v[u]; j--){
            for(int k = 0; k <= j - v[u]; k++){
                f[u][j] = max(f[u][j], f[u][j - k] + f[y][k]);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    
    int root = 1;
    
    for(int i = 1; i <= n; i++){
        int p;
        cin >> v[i] >> w[i] >> p;
        if(p == - 1) root = i;
        else g[p].push_back(i);
    }
    
    dfs(root);
    
    cout << f[root][m];
    
    return 0;
}