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

int f[35][35];

int main(){
	cin >> n >> m;
	
	// for(int i = 1; i <= max(n, m); i++){
		// f[i][1] = 1;
		// f[1][i] = 1;
	// }
	f[1][1] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1 && j == 1) continue;
			if((i % 2) || (j % 2)){
				// if(f[i - 1][j] && !f[i][j - 1]){
					// f[i][j] = f[i - 1][j];
				// }
				// else if(!f[i - 1][j] && f[i][j - 1]){
					// f[i][j] = f[i][j - 1];
				// }
				// else{
					f[i][j] = f[i - 1][j] + f[i][j - 1];
				// }
			}
		}
	}
	
	// for(int i = 1; i <= n; i++){
		// for(int j = 1; j <= m; j++)
			// cout << f[i][j] << " ";
		// cout << endl;
	// }
// 	
	
	cout << f[n][m];
	
	re 0;
}