// Problem: CF1520A Do Not Be Distracted!
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1520A
// Memory Limit: 250 MB
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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
char c[60];

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		scanf("%s", c);
		
		int cnt[26] = {0};
		memset(cnt, 0, sizeof(cnt));
		
		cnt[c[0] - 'A'] = 1;
		
		int t = 1;
		for(int i = 1; i < n; i++){
			if(c[i] == c[i - 1]){
				continue;
			}
			else{
				if(cnt[c[i] - 'A']){
					t = 0;
					break;
				}
				else{
					cnt[c[i] - 'A'] = 1;
				}
			}
		}
		
		if(t){
			cout << "YES" << Endl;
		}
		else{
			cout << "NO" << Endl;
		}
	}
	re 0;
}


