// Problem: Kruskal算法求最小生成树
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/861/
// Memory Limit: 64 MB
// Time Limit: 5000 ms
// Code by: ING__
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define ll long long
#define re return
#define Endl "\n"
#define endl "\n"

using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;

struct edge{
	int u, v, w;
}e[2 * N];

bool cmp(edge a, edge b){
	return a.w < b.w;
}

struct ufss{
	int f[N];
	
	void init(){
		for(int i = 1; i <= 100000; i++){
			f[i] = i;
		}
	}
	
	int query(int p){
		if(f[p] == p) return p;
		else{
			int v = query(f[p]);
			f[p] = v;
			return v;
		}
	}
	
	void merge(int p1, int p2){
		int f1 = query(p1);
		int f2 = query(p2);
		
		if(f1 != f2){
			f[f1] = f2;
		}
	}
}ufs;

int Kruskal(){
	int res = 0;
	int cnt = 0;
	ufs.init();
	
	sort(e + 1, e + 1 + m, cmp);
	
	for(int i = 1; i <= m; i++){
		int u = ufs.query(e[i].u);
		int v = ufs.query(e[i].v);
		
		if(u == v) continue;
		ufs.f[u] = v;
		cnt++;
		res += e[i].w;
	}
	
	if(cnt < n - 1) return INF;
	else return res;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i ++ )
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        e[i] = {a, b, w};
    }

    int t = Kruskal();

    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}
