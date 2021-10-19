// Problem: 楼层
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3658/
// Memory Limit: 256 MB
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
int n, x;

int l[1010];

int main(){
	l[1] = 2;
	cin >> T;
	while(T--){
		cin >> n >> x;
		int ans = 1;
		while(l[ans] < n){
			++ans;
			l[ans] = l[ans - 1] + x;
		}
		cout << ans << endl;
	}
	re 0;
}