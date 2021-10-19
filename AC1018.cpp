// Problem: 最大上升子序列和
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1018/
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

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int a[1010];
int f[1010];	

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		f[i] = a[i];
		for(int j = 1; j < i; j++){
			if(a[i] > a[j])
				f[i] = max(f[i], f[j] + a[i]);
		}
		ans = max(ans, f[i]);
	}
	
	cout << ans << endl;
	
	re 0;
}