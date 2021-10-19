// Problem: C. Yet Another Card Deck
// Contest: Codeforces - Educational Codeforces Round 107 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1511/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int q;
int a[55];

int main(){
	cin >> n >> q;
	for(int i = 1; i <= 55; i++){
		a[i] = 9999999;
	}
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		a[x] = min(a[x], i);
	}
	
	while(q--){
		int x;
		scanf("%d", &x);
		cout << a[x] << " ";
		for(int i = 1; i <= 50; i++){
			// if(x == i) continue;
			if(x == i) 
				a[x] = 1;
			else if(a[i] <= a[x]){
				a[i]++;
			}
		}
		// a[x] = 1;
	}
	re 0;
}


