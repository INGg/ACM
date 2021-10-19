// Problem: 友好城市
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1014/
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
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int n;
int f[5010];
PII a[5010];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y;
	}
	
	int ans = 0;
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1; i <= n; i++){
		f[i] = 1;
		for(int j = 1; j < i; j++){
			if(a[i].y > a[j].y){
				f[i] = max(f[i], f[j] + 1);
			}
		}
		ans = max(ans, f[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}