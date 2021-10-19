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

const int N = 1e6 + 10;

ll n, m, a, c;
ll x[N];
int backup[N];

int main(){
	cin >> n >> m >> a >> c >> x[0];
	
	// c %= m;
	
	for(int i = 1; i <= n; i++){
		x[i] = ((a % m * x[i - 1] % m) % m + c % m) % m;
	}
	
	// memcpy(backup, x, sizeof(x));
	
	// sort(backup + 1, backup + 1 + n);
	
	// for(int i = 1; i <= n; i++){
		// cout << x[i] << " ";
	// }
	// cout << endl;
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		
		ll b = x[i];
		
		int l = 1;
		int r = n;
	
		while(l < r){
			int mid = (l + r) >> 1;
			if(x[mid] == b){
				l = mid;
				break;
			}
			if(x[mid] > b){
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if(x[l] == b){
			ans ++;
		}
	}
	
	cout << ans;
	return 0;
}