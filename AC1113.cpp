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

int w, h;
char mapp[30][30];
bool vis[30][30];

int bfs(PII start){
	int cnt = 1;
	queue<PII> q;
	
	q.push(start);
	
	int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
	
	while(!q.empty()){
		PII f = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			
			if(x < 0 || x >= w || y < 0 || y >= h) continue;
			if(mapp[x][y] == '#') continue;
			if(vis[x][y]) continue;
			if(mapp[x][y] == '.'){
				cnt++;
				vis[x][y] = 1;
				q.push({x, y});	
			}
		}
	}
	
	return cnt;
}

int main(){
	while(cin >> h >> w && w && h){
		for(int i = 0; i < w; i++){
			scanf("%s",mapp[i]);
		}
		PII start;
		for(int i = 0; i < w; i++){
			for(int j = 0; j < h; j++){
				if(mapp[i][j] == '@'){
					start = {i, j};
					break;
				}
				// cout << mapp[i][j] << " ";
			}
			// cout << endl;
		}
		// cout << start.x << " " << start.y << endl;
		cout << bfs(start) << endl;
	}
	return 0;
}