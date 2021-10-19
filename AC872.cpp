// Problem: 约数个数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/872/
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
	for(auto i : primes)
		ans = ans * (i.second + 1) % mod;
	
	cout << ans << endl;
	
	return 0;
}