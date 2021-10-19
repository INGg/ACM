// Problem: 兔子跳
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3776/
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
int n;
int x;
int a[100000 + 10];

int main(){
	cin >> T;
	while(T--){
		cin >> n >> x;
		
		// int t1 = 0;
		// int t2 = 0;
		// int t3 = 0;
		int t = 0;
		int maxx = -1;
		
		memset(a, 0, sizeof(a));
		
		for(int i = 1; i <= n; i++){
			scanf("%d", a + i);
			if(a[i] == x){
				t = 1;
			}
			maxx = max(maxx, a[i]);
		}
		
		if(t){
			cout << 1 << endl;
			continue;
		}
		
		if(maxx >= x){
			cout << 2 << endl;
		}
		else{ // a 中最大的比x小
			if(x % maxx == 0){
				cout << x / maxx << endl;
			}
			else{
				cout << x / maxx + 1 << endl;
			}
		}
	}
	return 0;
}