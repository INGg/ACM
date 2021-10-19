// Problem: 字串变换
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/192/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-19 15:07:46

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

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
string a[8];
string b[8];

int extend(queue<string>& q, unordered_map<string, int>& ds, unordered_map<string, int>& de, string a[], string b[]){
	
	
	for(int k = 0, qs = q.size(); k < qs; k++){
	    string t = q.front();
	    q.pop();
	    
    	for(int i = 0; i < t.size(); i++){
    		for(int j = 0; j < n; j++){
    			if(t.substr(i, a[j].size()) == a[j]){
    				
    				string s = t.substr(0, i) + b[j] + t.substr(i + a[j].size());
    				
    				if(de.count(s)) return ds[t] + 1 + de[s];
    				if(ds.count(s)) continue;
    				
    				ds[s] = ds[t] + 1;
    				q.push(s);
    			}
    		}
    	}
	}
	return 11;
}

int bfs(string A, string B){
	queue<string> qs, qe;
	unordered_map<string, int> ds, de;
	
	qs.push(A);
	qe.push(B);
	ds[A] = 0;
	de[B] = 0;
	
	while(qs.size() && qe.size()){
		
		int t;
		if(qs.size() <= qe.size()) t = extend(qs, ds, de, a, b);
		else t = extend(qe, de, ds, b, a);
		
		if(t <= 10) return t;
	}
	
	return 11;
}

int main(){
	string A, B;
	cin >> A >> B;
	while(cin >> a[n] >> b[n]) n++;
	
	int step = bfs(A, B);
	
	if(step > 10) cout << "NO ANSWER!" << endl;
	else cout << step << endl;
}