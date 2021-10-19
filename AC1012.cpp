// Problem: 拦截导弹
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1012/
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

const int N = 1010;

int n = 1;
int a[N];
int f[N];
int q[N];

int main(){
	string s;
	getline(cin, s);
	stringstream ssin(s);
	while(ssin >> a[n]) n++;
	
	n--;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		f[i] = 1;
		for(int j = 1; j < i; j++){
			if(a[i] <= a[j]){
				f[i] = max(f[i], f[j] + 1);
			}
		}
		ans = max(f[i], ans);
	}
	cout << ans << endl;
	
	int len = 0;
	q[0] = -1;
	for(int i = 1; i <= n; i++){
		if(q[len] < a[i]) q[++len] = a[i];
		else{
			int id = lower_bound(q + 1, q + len + 1, a[i]) - q;
			q[id] = a[i];
		}
	}
	cout << len << endl;
	return 0;
}