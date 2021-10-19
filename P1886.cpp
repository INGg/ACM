// Problem: P1886 滑动窗口 /【模板】单调队列
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1886
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

const int N = 1000000 + 10;

int n, k;
int a[N];
int q[N];

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	int hh = 1;
	int tt = 0;
	
	for(int i = 1; i <= n; i++){
		if(hh <= tt && i - k + 1 > q[hh]) hh++;
		while(hh <= tt && a[q[tt]] >= a[i]) tt--;
		q[++tt] = i;
		if(i >= k) cout << a[q[hh]] << " ";
	}
	cout << endl;
	
	hh = 1;
	tt = 0;
	memset(q, 0, sizeof(q));
	
	for(int i = 1; i <= n; i++){
		if(hh <= tt && i - k + 1 > q[hh]) hh++;
		while(hh <= tt && a[q[tt]] <= a[i]) tt--;
		q[++tt] = i;
		if(i >= k) cout << a[q[hh]] << " ";
	}
	cout << endl;
	
	return 0;
}