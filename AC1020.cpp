// Problem: 最低通行费
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1020/
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
	scanf("%d", &r);
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= r; j++){
			scanf("%d", m[i] + j);
		}
	}
	
	memset(f, 0x3f, sizeof(f));
	
	f[1][1] = m[1][1];
	
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= r; j++){
			if(i == 1 && j == 1) continue;
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + m[i][j];
		}
	}
	
	printf("%d\n", f[r][r]);
}

int main(){
	work();
}

