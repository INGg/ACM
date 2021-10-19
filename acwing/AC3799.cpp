// Problem: 凑平方
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3799/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-07 19:03:36

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

bool check(ll x){
	ll t = sqrt(x);
	if(t * t == x){
		return 1;
	}
	else return 0;
}

bool vis[100]; //bool数组存好，还省空间

ll ans;
int T;
string nn;

void dfs(ll num, ll n){ 
    if(num > n){
    	ll cnt = 0;
    	string s = "";
    	ll flag = 0; // 是否出现过非0
        for (int i = 0; i <= n; i++){
            if(vis[i] == 1){
                s += nn[i];
                cnt++;      
                if(nn[i] != '0') flag = 1;
            }
        }
		stringstream ss;
		ss << s;
		ll x;
		ss >> x;
		// cout << x << Endl;
		if(x && check(x)){
			// cout << x << Endl;
			ans = min(ans, (ll)nn.size() - (ll)to_string(x).size());
		}
        return;
    }

    vis[num] = 1; //选他
    dfs(num + 1, n);
    vis[num] = 0; //恢复现场加不选他
    dfs(num + 1, n);
    vis[num] = 0; //恢复现场
}



int main(){
	cin >> T;
	while(T--){
		ans = 0x3f3f3f3f;
		memset(vis, 0, sizeof(vis));
		
		nn.clear();
		
		cin >> nn;
		
		dfs(0, nn.size() - 1);
		// cout << ans << endl;
		
		if(ans > 99999)
			cout << -1 << endl;
		else cout << ans << endl;
	}
}