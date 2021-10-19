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

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m, k;

int D[210][210];

void init(){ // 邻接矩阵的初始化
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) D[i][j] = 0;
			else D[i][j] = 1e9;
		}
	}
}

void fl(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
}

int main(){
	cin >> n >> m >> k;
	
	init();
	
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		D[x][y] = min(D[x][y], z);
	}
	
	fl();
	
	while(k--){
		int x, y;
		cin >> x >> y;
		if(D[x][y] >= 1e9 / 2) cout << "impossible" << endl;
		else cout << D[x][y] << endl;
	}
	
	return 0;
}