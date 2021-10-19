// Problem: P3375 【模板】KMP字符串匹配
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3375
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e6 + 10, M = 1e6 + 10;

int n, m;
char p[N];
char s[M];
int ne[N];

int main(){

	scanf("%s", s + 1);
	m = strlen(s + 1);
	scanf("%s", p + 1);
	n = strlen(p + 1);
	// cout << n << endl;
	
	for(int i = 2, j = 0; i <= n; i++){
		while(j && p[i] != p[j + 1]) j = ne[j];
		if(p[i] == p[j + 1]) j++;
		ne[i] = j;
	}
	
	for(int i = 1, j = 0; i <= m; i++){
		while(j && s[i] != p[j + 1]) j = ne[j];
		if(s[i] == p[j + 1]) j++;
		if(j == n){
			cout << i - n + 1<< endl;
			j = ne[j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << ne[i] << " ";
	}
	return 0;
}