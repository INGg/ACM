// Problem: P1003 [NOIP2011 提高组] 铺地毯
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1003
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

int n;

struct nope{
	int a;
	int b;
	int dx;
	int dy;
}d[10000 + 10];

int x, y;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int a, b, c, e;
		cin >> a >> b >> c >> e;
		d[i] = {a, b, c, e};
	}
	cin >> x >> y;
	
	for(int i = n; i >= 1; i--){
		if(x >= d[i].a && x <= d[i].a + d[i].dx - 1 && y >= d[i].b && y <= d[i].b + d[i].dy - 1){
			cout << i;
			return 0;
		}
	}
	
	cout << -1;
	re 0;
}