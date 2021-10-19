// Problem: P2678 [NOIP2015 提高组] 跳石头
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2678
// Memory Limit: 125 MB
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

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int x, m, n;

int d[50000 + 10];

int len[50000 + 10];

bool check(int le){
	int cnt = 0;
	
	int i = 0;
	int now = 0;
	
	while(i < n + 1){
		i++;
		if(d[i] - d[now] < le){
			cnt++;
		}
		else{
			now = i;
		}
	}
	
	return m >= cnt;
	
}

int main(){
	cin >> x >> n >> m;
	
	int l = 1;
	int r = x;
	
	for(int i = 1; i <= n; i++){
		cin >> d[i];
	}
	
	d[n + 1] = x;
	
	
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	
	cout << r << Endl;
}

