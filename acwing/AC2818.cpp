// Problem: 判断子序列
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/2818/
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

int n, m;
int a[N];
int b[N];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= m; i++){
		cin >> b[i];
	}
	
	for(int i = 1, j = 1; j < m; j++){
		if(a[i] == b[j]){
			i++;
			if(i == n){
				cout << "Yes";
				return 0;
			}
		}
	}
	
	cout << "No";
	
	return 0;
}