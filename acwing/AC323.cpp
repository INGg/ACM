// Problem: 棋盘分割
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/323/
// Memory Limit: 10 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-11 15:08:57

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

const int m = 8;
const int N = 15, M = 9;

int n;
int s[M][M];
double f[M][M][M][M][N];
double xba;

double get(int x1, int Y1, int x2, int y2){ // 算均方差的平方
	double summ = s[x2][y2] - s[x1 - 1][y2] - s[x2][Y1 - 1] + s[x1 - 1][Y1 - 1] - xba;
	return summ * summ / n;
}

double dp(int x1, int Y1, int x2, int y2, int k){
	double &v = f[x1][Y1][x2][y2][k];
	if(v >= 0) return v;
	if(k == 1) return v = get(x1, Y1, x2, y2);
	
	v = 1e9;
	
	for(int i = x1; i < x2; i++){
		v = min(v, get(x1, Y1, i, y2) + dp(i + 1, Y1, x2, y2, k - 1));
		v = min(v, get(i + 1, Y1, x2, y2) + dp(x1, Y1, i, y2, k - 1));
	}
	
	for(int i = Y1; i < y2; i++){
		v = min(v, get(x1, Y1, x2, i) + dp(x1, i + 1, x2, y2, k - 1));
		v = min(v, get(x1, i + 1, x2, y2) + dp(x1, Y1, x2, i, k - 1));
	}
	
	return v;
}

int main(){
	cin >> n;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			cin >> s[i][j];
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	
	memset(f, -1, sizeof(f));
	xba = (double)s[m][m] / n;
	
	printf("%.3lf", sqrt(dp(1, 1, 8, 8, n)));
	
	return 0;
}