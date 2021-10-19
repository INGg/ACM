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

using namespace std;

typedef pair<int, int> PII;

struct node{
	int x;
	int y;
	int z;
};

int dx[6] = {-1,0,1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

char mapp[110][110][110];
int l, r, c; // L,R,C  分别表示地牢层数，以及每一层地牢的行数和列数。
int dis[110][110][110];

int bfs(node start, node end){
	memset(dis, -1, sizeof(dis));
	
	dis[start.x][start.y][start.z] = 0;
	
	queue<node> q;
	
	q.push(start);
	
	while(!q.empty()){
		node f = q.front();
		q.pop();
		for(int i = 0; i < 6; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			int z = f.z + dz[i];
			
			if(x < 0 || x >= l || y < 0 || y >= r || z < 0 || z >= c) continue;
			if(mapp[x][y][z] == '#') continue;
			if(dis[x][y][z] != -1) continue;
			
			dis[x][y][z] = dis[f.x][f.y][f.z] + 1;
			
			
			if(end.x == x && end.y == y && end.z == z) return dis[x][y][z];
			
			
			
			q.push({x,y,z});
			
		}
	}
	return -1;
}

int work(){
	cin >> l >> r >> c;
	if(!l && !r && !c) return 0;
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < r; j++){
			scanf("%s",mapp[i][j]);
		}
	}
	
	node start, end;
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < r; j++){
			for(int k = 0; k < c; k++){
				if(mapp[i][j][k] == 'S') start = {i, j, k};
				if(mapp[i][j][k] == 'E') end = {i, j, k};
			}
		}
	}
	
	int d = bfs(start, end);
	if(d == -1) cout << "Trapped!" << endl;
	else printf("Escaped in %d minute(s).\n", d	);
	return 1;
}

int main(){
	while(work() != 0);
	return 0;
}