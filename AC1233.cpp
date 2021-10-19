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
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;

char mapp[1000 + 10][1000 + 10];
bool vis[1000 + 10][1000 + 10];

int bfs(int xx, int yy){
	queue<PII> q;
	
	q.push({xx, yy});
	vis[xx][yy] = 1;
	
	int earth = 0;
	int sea = 0;
	
	while(!q.empty()){
		PII f = q.front();
		q.pop();
		
		int t = 0; //看这个点的四个方向的情况！注意，要完全理解flood fill算法中每一步具体是干什么的
		earth++;
		
		for(int i = 0; i < 4; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			
			if(x < 0 || x >= n || y < 0 || y >= n) continue;
			if(vis[x][y] == 1) continue;
			if(mapp[x][y] == '.'){
				t = 1;
				continue;
			}

			vis[x][y] = 1;
			
			q.push({x, y});
		}
		if(t) sea ++;
	}
	
	return sea == earth;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%s", mapp[i]);
	}
	
	int cnt = 0; //看连通块的数量
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(vis[i][j] == 0 && mapp[i][j] == '#'){
				int x = bfs(i, j);
				// cout << x << endl;
				if(x) cnt++;
			}
		}
	}
	
	// for(int i = 0; i < )
	cout << cnt;
	return 0;
}