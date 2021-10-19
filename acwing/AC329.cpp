// Problem: 玉米田
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/329/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-05 15:12:48

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
#define pb push_back
#define re return
#define Endl "\n"
#define endl "\n"

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

const int N = 13;
const int M = (1 << N);
const int mod = 1e8;

int g[N];
int n, m;
vector<int> stats;
vector<int> head[M];
int f[N][M];

bool check(int x){
	for(int i = 0; i < m; i++){ // 一行的每种状态
		if(((x >> i) & 1) && ((x >> (i + 1)) & 1))
			return 0;
	}
	return 1;
}

void init(){
	for(int i = 0; i < (1 << m); i++){ // 一行的每种状态，一行有m位
		if(check(i)){
			stats.pb(i);
		}
	}
	
	for(int i = 0; i < stats.size(); i++){
		for(int j = 0; j < stats.size(); j++){
			int a = stats[i];
			int b = stats[j];
			if((a & b) == 0){
				head[i].pb(j);
			}
		}
	}
}

int main(){
	cin >> n >> m;
	init();
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			int t;
			cin >> t;
			g[i] += (!t << j); // 用1表示不能放玉米，为了后面好进行位运算
		}
	}
	
	f[0][0] = 1; // 初始化，什么都不种也算一种方法
	
	for(int i = 1; i <= n + 1; i++){
		for(int x = 0; x < stats.size(); x++){
			for(int y = 0; y < head[x].size(); y++){
				int a = stats[x];
				int b = stats[head[x][y]];
				
				if(g[i] & a) continue;
				/*
				因为上面我们用的是1来表示的不能放，而我们状态中用1表示的是能放，
				那么两种状态表示的方法按位与运算得出来的的结果只要有1就说明实际上是冲突的，是不合法的
				*/
				f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
			}
		}
	}
	
	cout << f[n + 1][0];
	
	return 0;
}