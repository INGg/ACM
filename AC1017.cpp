// Problem: 摘花生
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/1017/
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

int T;
int r, c;
int m[110][110];
int f[110][110];

void work(){
	scanf("%d%d", &r, &c);
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			scanf("%d", m[i] + j);
		}
	}
	
	memset(f, 0, sizeof(f));
	
	f[1][1] = m[1][1];
	
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			f[i][j] = max(f[i - 1][j], f[i][j - 1]) + m[i][j];
		}
	}
	
	printf("%d\n", f[r][c]);
}

int main(){
	cin >> T;
	while(T--){
		work();
	}
}