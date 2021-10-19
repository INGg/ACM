// Problem: 亮灯时长
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3777/
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

int T;
int n, m;
int a[100000 + 10];

int main(){
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		int ans = a[1];
		int maxx = 0;
		int x = 0;
		for(int i = 2; i <= n; i++){
			if(!x){
				x = 1;
				maxx = max(maxx, a[i] - a[i - 1]); 
			}
			else{
				x = 0;
			}
		}
		
		if(!x) maxx = max(maxx, m - a[n]);
		
		cout << ans + maxx - 1 << endl;
	}
}