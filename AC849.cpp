#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
int g[520][520];
bool vis[520];
int dis[520];

int dijkstra(){
	memset(dis, 0x3f, sizeof(dis));
	
	dis[1] = 0;
	
	for(int i = 1; i < n; i ++){
		int x = -1;
		
		for(int j = 1; j <= n; j++){
			if(!vis[j] && (x == -1 || dis[x] > dis[j])) x = j;
		}
		
		vis[x] = 1;
		
		for(int j = 1; j <= n; j++){
			dis[j] = min(dis[j], dis[x] + g[x][j]);
		}
	}
	
	if(dis[n] == 0x3f3f3f3f) return -1;
	
	return dis[n];
}

int main(){
	cin >> n >> m;
	
	memset(g, 0x3f, sizeof(g)); 
	
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z); // 因为可能有重边，所以最短路肯定是取两点之间最短的那个就可以了
		// 自环一定不会出现在最短路里，因为会增加长度（全是正权）
	}
	
	int d = dijkstra();
	
	cout << d << endl;
	
	return 0;
}