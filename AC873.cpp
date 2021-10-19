// Problem: 约数之和
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/873/
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
#include <unordered_map>
#define ll long long
#define re return
#define Endl "\n"
#define endl "\n"

using namespace std;

const int mod = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	
	unordered_map<int, int> primes;
	
	while(n--){
		int x;
		cin >> x;
		for(int i = 2; i <= x / i; i++){
			while(x % i == 0){
				x /= i;
				primes[i] ++;
			}
		}
		if(x > 1){
			primes[x] ++;
		}
	}
	
	ll ans = 1;
	for(auto i : primes){
		ll t = 1;	
		ll a = i.first;
		ll b = i.second;
		while(b--){
			t = (t * a + 1) % mod;
		}
		ans = ans * t % mod;
	}
	cout << ans << endl;
	
	return 0;
}