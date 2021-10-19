// Problem: 方格取数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1029/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int w[20][20];
int f[30][20][20];

int main(){
	cin >> n;
	int x, y, v;
	while(cin >> x >> y >> v, x && y && v){
		w[x][y] = v;
	}
	
	for(int k = 2; k <= 2 * n; k++){
		for(int i1 = 1; i1 <= n; i1++){
			for(int i2 = 1; i2 <= n; i2++){
				int j1 = k - i1;
				int j2 = k - i2;
				if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n){
					int t = w[i1][j1];
					if(i1 != i2) t += w[i2][j2];
					
					
					f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2 - 1] + t);
					f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2] + t);
					f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1][i2 - 1] + t);
					f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1][i2] + t);
				}
			}
		}
	}
	
	cout << f[n + n][n][n];
	return 0;
}