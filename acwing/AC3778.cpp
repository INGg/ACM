// Problem: Êý×é²¹È«
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3778/
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
#include <time.h>
#include <sstream>
#define ll long long
#define re return
#define Endl "\n"
#define endl "\n"

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

const int N = 2e5 + 10;

int T;
int n;
int a[N];
int f[N];
bool vis[N];

int main(){
	
	cin >> T;
	while(T--){
		srand(time(0));
		cin >> n;
		
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		
		int idx_a = 0;

		for(int i = 1; i <= n; i++){
			scanf("%d", f + i);
			if(f[i]){
				vis[f[i]] = 1;
			}
		}
		
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				a[++idx_a] = i;
			}
		}
		
		// cout << idx_a << endl;
		
		random_shuffle(a + 1, a + 1 + idx_a);
		random_shuffle(a + 1, a + 1 + idx_a);
		random_shuffle(a + 1, a + 1 + idx_a);
		
		for(int i = 1, j = 1; i <= n; i++){
			if(!f[i]){
				printf("%d ", a[j]);
				j++;
			}
			else{
				printf("%d ", f[i]);
			}
		}
		printf("\n");
	}
	return 0;
}