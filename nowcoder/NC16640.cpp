// Problem: [NOIP2007]纪念品分组
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/16640
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
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

int w;
int n;
int p[30010];
bool vis[30010];

int main(){
	cin >> w >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	
	int ans = 0;
	sort(p + 1, p + 1 + n);
	
	for(int i = 1, j = n; i <= j; j--){
		// cout << p[i] << endl;
		if(p[i] + p[j] > w){
			vis[j] = ++ans;
		}
		else{
			vis[j] = ++ans;
			vis[i] = ans;
			i++;
		}
	}
	
	cout << ans;
	return 0;
}