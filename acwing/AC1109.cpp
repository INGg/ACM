// Problem: 魔板
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1109/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-13 14:29:20

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
#define ull unsigned long long
#define re return
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

char g[2][4];
unordered_map<string, int> dis;
unordered_map<string, pair<char, string>> pre; // 前面的string由后面的string通过char操作来得到的

void get(string s){ // 变回数组
	for(int i = 0; i < 4; i++) g[0][i] = s[i];
	for(int i = 4, j = 3; j >= 0; j--, i++) g[1][j] = s[i];
}

string set_string(){
	string res;
	
	for(int i = 0; i < 4; i++) res += g[0][i];
	for(int i = 3; i >= 0; i--) res += g[1][i];
	
	return res;
}

string opA(string s){
	get(s);
	
	for(int i = 0; i < 4; i++){
		swap(g[0][i], g[1][i]);
	}
	
	return set_string();
}

string opB(string s){
	get(s);
	
	char c1 = g[0][3];
	char c2 = g[1][3];
	for(int i = 3; i >= 1; i--){
		g[0][i] = g[0][i - 1];
		g[1][i] = g[1][i - 1];
	}
	g[0][0] = c1;
	g[1][0] = c2;
	
	return set_string();
}

string opC(string s){
	get(s);
	
	char c = g[0][1];
	g[0][1] = g[1][1];
	g[1][1] = g[1][2];
	g[1][2] = g[0][2];
	g[0][2] = c;
	
	return set_string();
}

void bfs(string s, string e){
    
    // exit(0);
	
	if(s == e) return;
	
	queue<string> q;
	
	q.push(s);
// 	exit(0);
	dis[s] = 0;
	
	while(!q.empty()){
		auto t = q.front();
		
		q.pop();
		
		string st[3];
		
		st[0] = opA(t);
// 		exit(0);
		st[1] = opB(t);
// 		exit(0);
		st[2] = opC(t);
        // exit(0);		
		
// 		for(int i = 0; i < 3; i++){
// 		    cout << st[i] << endl;
// 		}
// 		exit(0);
// 		break;
		
		for(int i = 0; i < 3; i ++){
			if(dis.count(st[i]) == 0){
				
				dis[st[i]] = dis[t] + 1;
				
				pre[st[i]] = {'A' + i, t};
				
				q.push(st[i]);
				
				if(st[i] == e) return;
			}
		}
	}
}

int main(){
	string start;
	string end;
	
	for(int i = 0; i < 8; i++){
		int a;
		cin >> a;
		end += (char)(a + '0');
	}
	
	start = "12345678";
	
	bfs(start, end);
	
	if(dis[end]) cout << dis[end] << endl;
	else{
		cout << 0 << endl;
		return 0;
	}
	
	string ans;
	while(start != end){
		ans += pre[end].x;
		end = pre[end].y;
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << ans;
	
	return 0;
}