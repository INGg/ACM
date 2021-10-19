// Problem: A. Message
// Contest: Codeforces - Codeforces Round #110 (Div. 1)
// URL: https://codeforces.com/problemset/problem/156/A
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

char a[2010];
char b[2010];
int f[2010][2010];

int main(){
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	
	int la = strlen(a + 1);
	int lb = strlen(b + 1);
	
	int ans = 0;
	
	for(int i = 1; i <= la; i++){
		for(int j = 1; j <= lb; j++){
			if(a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = f[i - 1][j - 1];
			ans = max(ans, f[i][j]);
		}
	}
	
	cout << lb - ans;
}