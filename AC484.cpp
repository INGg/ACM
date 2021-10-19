// Problem: 合唱队形
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/484/
// Memory Limit: 128 MB
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

int n;
int h[1010];
int f[1010];
int f2[1010];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
	}
	
	for(int i = 1; i <= n; i++){
		f[i] = 1;
		for(int j = 1; j <= i; j++){
			if(h[i] > h[j])
				f[i] = max(f[i], f[j] + 1);
		}
	}
	
	int ans = 0;
	
	for(int i = n; i >= 1; i--){
		f2[i] = 1;
		for(int j = n; j >= i; j--){
			if(h[i] > h[j])
				f2[i] = max(f2[i], f2[j] + 1);
		}
		ans = max(ans, f2[i] + f[i] - 1);
	}
	
	cout << ans;

	return 0;
}