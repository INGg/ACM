#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

const int N = 510;
const int M = 10000 + 10;

int n, m, k;
int dis[N];
int backup[N];

struct Edge{
	int u;
	int v;
	int w;
}edge[M];

int bellman_ford(int s){
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	
	for(int i = 1; i <= k; i++){
		memcpy(backup, dis, sizeof(dis)); // 备份一下，保证每次迭代都是从上层迭代来的
		
		for(int j = 1; j <= m; j++){
			int u = edge[j].u, v = edge[j].v, w = edge[j].w;
			
			dis[v] = min(dis[v], backup[u] + w);
		}
	}
	
	if(dis[n] > 0x3f3f3ff3 / 2) return -1;
	else return dis[n];
}

int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	
	int t = bellman_ford(1);
	
	if(t == -1) puts("impossible");
	else{
		cout << t;
	}
}