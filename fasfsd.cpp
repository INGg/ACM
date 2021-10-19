// Problem: Ssyze's Hard Drive
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/15084/F
// Memory Limit: 2097152 MB
// Time Limit: 4000 ms
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

ll a[1000000 + 10];
ll summ;
ll n, s;

int main(){
	cin >> n >> s;
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
	}
	
	sort(a + 1, a + 1 + n);
	
	// auto it = lower_bound(a + 1, a + 1 + n, s);
	
	if(s <= a[1]){
		summ = abs(s - a[1]);
		for(int i = 2; i <= n; i++){
			summ += abs(a[i] - a[i - 1]);
		}
		cout << summ;
	}
	else if(s >= a[n]){
		summ = abs(s - a[n]);
		for(int i = n; i >= 2; i--){
			summ += abs(a[i] - a[i - 1]);
		}
		cout << summ;
	}
	else{
		// 先去左边
		auto it = lower_bound(a + 1, a + 1 + n, s) - a; // 找到第一个大于等于s的坐标
		// cout << a[it] << endl;
		if(abs(s - a[1]) <= abs(s - a[n])){
			summ = abs(s - a[it]);
            cout << abs(s - a[it]) << endl;
            for(int i = it; i >= 2; i--){
				summ += abs(a[i] - a[i - 1]);
                cout << abs(a[i] - a[i - 1]) << endl;
            }
			for(int i = 2; i <= n; i++){
				summ += abs(a[i] - a[i - 1]);
                cout << abs(a[i] - a[i - 1]) << endl;
			}
			cout << summ;
		}
		else{
			summ = abs(s - a[it]); // 现在在it点
			for(int i = it + 1; i <= n; i++){
				summ += abs(a[i] - a[i - 1]);
			}
			for(int i = n; i >= 2; i--){
				summ += abs(a[i] - a[i - 1]);
			}
			cout << summ;
		}
	}
	re 0;
}