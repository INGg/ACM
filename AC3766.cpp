// Problem: 数字矩阵
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3766/
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
int n, m;

int main(){
	cin >> T;
	while(T--){
		
		cin >> n >> m;
		
		int ans = 0;
		int minn = 9999;
		int cnt = 0;
		
		
		for(int i = 1; i <= n * m; i++){
			int x;
			cin >> x;
			ans += abs(x);
			
			if(x < 0){
				cnt ++;
			}
			minn = min(minn, abs(x));
		}
		
		if(cnt & 1){ // ji
			ans = ans - 2 * minn;
		}
		
		cout << ans << endl;
	}
}