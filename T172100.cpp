#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define ll long long
#define re return

#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long

using namespace std;

int main(){
	int n;
	int m;
	cin >> n >>m;
	int w[100000 +10];
	int c[100000 + 10];
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> c[i];
	}
	
	int ans = 0;
	sort(w + 1, w + 1 + n);
	sort(c + 1, c + 1 + m);
	
	for(int i = n, j = m; i >= 1 && j >= 1; j--){
		if(w[i] >= c[j]){
			ans ++;
			i--;
		}
	}
	cout << ans;
	return 0;
}