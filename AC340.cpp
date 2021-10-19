// Problem: 计数问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/340/
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

int power10(int n){
	int ans = 1;
	while(n--){
		ans *= 10;
	}
	return ans;
}

int wei(int n){
	int ans = 0;
	while(n){
		n /= 10;
		ans++;
	}
	return ans;
}

int count(int n, int x){
	
	if(!n) return 0;
	
	int w = wei(n);
	
	int ans = 0;
	
	for(int i = 1; i <= w; i++){
		int j = power10(w - i); // 这里为什么是w - i而不是 i 呢；因为我们这里的第 i 位是十进制下的从左往右的位，也就是从大到小的位数来看的
		int r = n % j;
		int l = n / j / 10;
		int d = n / j % 10;
		// cout << l << ' ' << r << " " << d << endl;
		if(x) ans += l * j;
		else ans += (l - 1) * j;
		
		if(d == x) ans += r + 1;
		if(d > x) ans += j;
	}
	
	return ans;
}

int main(){
	int a, b;
	while(cin >> a >> b, a || b){
		if (a > b) swap(a, b);
		for(int i = 0; i <= 9; i++){
			cout << count(b, i) - count(a - 1, i) << " ";
		}
		cout << endl;
	}
	return 0;
}