// Problem: FBI树
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/421/
// Memory Limit: 128 MB
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

void dfs(string s){
	if(s.size() > 1){
		dfs(s.substr(0, s.size() / 2));
		dfs(s.substr(s.size() / 2));
	}
	int o = 0;
	int z = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1') o ++;
		else z++;
	}
	if(o == s.size()){
		cout << 'I';
	}
	else if(z == s.size()){
		cout << 'B';
	}
	else cout << 'F';
}

int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	dfs(s);
	re 0;
}