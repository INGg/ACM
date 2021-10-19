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

char mapp[110][110];
int T;
int r, c;
int vis[110][110];
int n;

void bfs(PII start, int &cnt){
	cnt++;
	
	queue<PII> q;
	
	vis[start.x][start.y] = 1;
	
	q.push(start);
	
	// int cnt = 0;
	
	while(!q.empty()){
		PII f = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			
			if(x < 0 || x >= r || y < 0 || y >= c) continue;
			if(vis[x][y]) continue;
			if(mapp[x][y] == '0') continue;
			
			vis[x][y] = 1;
			q.push({x, y});
		}
	}
}

void work(int num){
	memset(mapp, 0, sizeof(mapp));
	// memset(vis, 0, sizeof(vis));
	
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		scanf("%s", mapp[i]);
	}
	printf("Case #%d:\n", num);
	cin >> n;
	while(n--){
		char cc;
		int x, y, z;
		cin >> cc;
		if(cc == 'M'){
			scanf("%d%d%d", &x, &y, &z);
			mapp[x][y] = '0' + z;
		}
		else{
			memset(vis, 0, sizeof(vis));
			int cnt = 0;
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					if(vis[i][j] == 0 && mapp[i][j] == '1'){
						bfs({i, j}, cnt);
					}
				}
			}
			printf("%d\n", cnt);
		}
	}
}

int main(){
	cin >> T;
	for(int i = 1; i <= T; i++){
		work(i);
	}
	return 0;
}