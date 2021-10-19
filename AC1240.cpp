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
ll a[1000000 + 10];
ll s[1000000 + 10];

int main(){
	cin >> n;
	for(int i = 1 ; i <= n; i++){
		scanf("%lld", a + i);
	}

	int ans = 1;
	ll maxx = -1;

	for(int i = 1, d = 1; i <= n; i <<= 1, d++){
		ll summ = 0;
		for(int j = i; j < i + (1 << (d - 1)); j++){
			summ += a[j];
		}
		
		if(summ > maxx){
			maxx = summ;
			ans = d;
		}
	}

	cout << ans;
	return 0;
}