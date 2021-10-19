// Problem: P1083 [NOIP2012 提高组] 借教室
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1083
// Memory Limit: 125 MB
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

int n, m;

ll a[1000000 + 10];
ll b[1000000 + 10];

struct{
	int d;
	int s;
	int t;
}o[1000000 + 10];

bool check(int x){
	
	memset(b, 0, sizeof(b));
	
	int flag = 1;
	cout << x << endl;
	
	for(int i = 1; i <= n; i++){
		// b[i] = a[i] - a[i - 1];
		
		b[i] += a[i];
		b[i + 1] -= a[i];
		
		cout << i << " : " << b[i] << endl;
	}
	
	cout << endl;
	
	for(int i = 1; i <= x; i++){
		b[o[i].s] += (-o[i].d);
		b[o[i].t + 1] -= (-o[i].d); 
	}
	
	for(int i = 1; i <= n; i++){
		b[i] +=	 b[i - 1];
		if(b[i] < 0){
			flag = 0;
			break;
		}
	}
	
	
	if(flag) return 1;
	else return 0;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
	}
	
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &o[i].d, &o[i].s, &o[i].t);
	}
	
	if(check(m)){
		cout << 0;
		re 0;
	}
	
	int l = 1;
	int r = m;
	while(l < r){
		int mid = (l + r) >> 1;
		
		if(!check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	
	cout << -1 << endl;
	cout << l << Endl;
	
	re 0;
}


