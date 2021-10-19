// Problem: Floyd求最短路
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/856/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
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

const int INF = 0x3f3f3f3f;

int n, m, k;
int D[210][210];

void init(){
	for(int i = 1; i <= 200; i++){
		for(int j = 1; j <= 200; j++){
			if(i == j) D[i][j] = 0;
			else D[i][j] = INF;
		}
	}
}

void Floyed(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
}

int main(){
	init();
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		D[x][y] = min(D[x][y], z);
	}
	
	Floyed();
	
	while(k--){
		int x, y;
		cin >> x >> y;
		if(D[x][y] > INF / 2) cout << "impossible" << endl;
		else cout << D[x][y] << endl;
	}
	
	return 0;
}