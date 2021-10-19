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

int n;
ll a[100000 + 10];
map<ll, int> m;

int main(){
	
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		// alls.push_back(a[i]);
	}
	
	ll ans = 0;
	
	for(int i = 1, j = 1; j <= n; j++){
		m[a[j]] ++;
		while(m[a[j]] > 1){
			m[a[i]] --;
			i++;
		}
		ans += j - i + 1;
	}
	
	cout << ans;
	
	return 0;
}