// Problem: 怪盗基德的滑翔翼
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1019/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int k;
int n;
int h[110];
int f[110];

int main(){
	cin >> k;
	while(k--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			scanf("%d", h + i);
		}
		
		memset(f, 0 , sizeof(f));
		int ans = 0;
		
		for(int i = 1; i <= n; i++){
			f[i] = 1;
			for(int j = 1; j <= i; j++){
				if(h[i] < h[j]){
					f[i] = max(f[i], f[j] + 1);
				}
			}
			ans = max(ans, f[i]);
		}
		
		for(int i = 1; i <= n; i++){
			f[i] = 1;
			for(int j = 1; j <= i; j++){
				if(h[i] > h[j]){
					f[i] = max(f[i], f[j] + 1);
				}
			}
			ans = max(ans, f[i]);
		}
		
		cout << ans << endl;
	}
}