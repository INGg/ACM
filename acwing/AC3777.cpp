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

const int N = 1e5 + 10;

int T;
int n, m;
int a[N];
int sj[N];
int so[N];

int main(){
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		a[++n] = m;
		
		// int flag = 0;
		
		memset(sj, 0, sizeof(sj));
		memset(so, 0, sizeof(so));
		
		for(int i = n - 1; i >= 0; i--){
			sj[i] = sj[i + 1];
			so[i] = so[i + 1];
			if(i % 2 == 0){
				sj[i] += a[i + 1] - a[i];
			}
			else{
				so[i] += a[i + 1] - a[i];
			}
		}
		
		int ans = sj[0];
		
		for(int i = 0; i < n; i++){
			int t = a[i + 1] - a[i];
			if(t == 1) continue;
			ans = max(ans, t - 1 - sj[i] + sj[0] + so[i + 1]);
		}
		
		cout << ans << endl;
	}
}