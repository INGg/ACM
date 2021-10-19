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

int n, m;
int f[100000 + 10];

void init(){
	for(int i = 1; i <= n; i++){
		f[i] = i;
	}
}

int query(int p){
	if(f[p] == p){
		return p;
	}
	else{
		return f[p] = query(f[p]);
	}
}

void merge(int p, int q){
	int f1 = query(p);
	int f2 = query(q);
	
	if(f1 != f2){
		f[f1] = f2;
	}
}

int main(){
	cin >> n >> m;
	init();
	while(m--){
		char c;
		int a, b;
		cin >> c >> a >> b;
		if(c == 'M') merge(a, b);
		else{
			if(query(f[a]) == query(f[b])){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
	}
	re 0;
}