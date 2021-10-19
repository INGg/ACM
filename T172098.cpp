// Problem: T172098 子串
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T172098?contestId=42343
// Memory Limit: 128 MB
// Time Limit: 1000 ms
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
#define ll long long
#define re return

#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long


using namespace std;

int main(){
	int T;
	cin >> T;
	while (T--){
		int n, m;
		ll ans = 0;

		string a, b;
		cin >> n >> m;
		cin >> a >> b;

		for (int i = 0; i < a.size(); i++){
			a[i] = tolower(a[i]);
		}

		for (int i = 0; i < b.size(); i++){
			b[i] = tolower(b[i]);
		}

		for (int i = 0; i < b.size(); i++){
			if (b[i] == a[0]){
				bool flag = true;
				for (int j = 0; j < a.size(); j++){
					if (b[i + j] != a[j]){
						flag = false;
						break;
					}
				}

				if (flag){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
