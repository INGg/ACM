// Problem: C. Berland Regional
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1519/problem/C
// Memory Limit: 256 MB
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

int T;
vector<int> v[200000 + 10];
vector<ll> s[200000 + 10];
int n;

struct nope{
	int u;
	int s;
}a[200000 + 10];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		int nn = -1;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i].u);
		}
		
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i].s);
			v[a[i].u].push_back(a[i].s);
		}
		
		int maxx = 0;
		
		for(int i = 1; i <= n; i++){
			sort(v[i].begin(), v[i].end(), cmp);
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < v[i].size(); j++){
				s[i][j + 1] = s[i][j] + v[i][j];
				cout << s[i][j] << " ";
			}
			cout << endl;
		}
		
		for(int i = 1; i <= n; i++){
			
		}
	}
}