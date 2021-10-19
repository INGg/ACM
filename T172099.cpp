#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define ll long long
#define re return
// typedef pair<int,int> PII;

using namespace std;

#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long

int a[51];
int b[51];
int c[51];

int main() 
{
	int n;
	int m;
	cin >> n >> m;

	int x;
	for (int i = 1; i <= n; i++){
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= n; i++){
		cin >> x;
		b[x]++;
	}
	for (int i = 1; i <= n; i++){
		cin >> x;
		c[x]++;
	}

	int maxx = -1;
	int cnt = 1;
	int now = 1;
	while (1){
		int flag = 0;
		for (int i = 1; i <= m; i++){
			if (now == 1){
				cnt = 1;
				maxx = 0;
			}

			if (i > maxx && a[i] >= cnt){
				a[i] -= cnt;
				maxx = i;
				flag = 1;
				now = 1;
				break;
			}
		}

		if (flag == 0){
			int num = cnt;
			while (++num <= n){
				bool t = 0;

				for (int i = 1; i <= m; i++){
					if (a[i] >= num){
						a[i] -= num;
						maxx = i;
						cnt = num;
						flag = 1;
						t = 1;
						now = 1;
						break;
					}
				}

				if (t) break;
			}
		}

		flag = 0;
		for (int i = 1; i <= 50; i++){
			if (a[i] != 0){
				flag = 1;
				break;
			}
		}
		if (!flag){
			cout << "1" << endl;
			return 0;
		}
		

		flag = 0;
		for (int i = 1; i <= m; i++){
			if (now == 2){
				cnt = 1;
				maxx = 0;
			}
			if (i > maxx && b[i] >= cnt){
				b[i] -= cnt;
				maxx = i;
				flag = 1;
				now = 2;
				break;
			}
		}

		if (!flag){
			int num = cnt;
			while (++num <= n){
				bool t = 0;
				for (int i = 1; i <= m; i++){
					if (b[i] >= num){
						b[i] -= num;
						maxx = i;
						cnt = num;
						flag = 1;
						t = 1;
						now = 2;
						break;
					}
				}
				if (t)	break;
			}
		}

		flag = 0;
		for (int i = 1; i <= 50; i++){
			if (b[i] != 0){
				flag = 1;
				break;
			}
		}
		if (!flag){
			cout << "2" << endl;
			return 0;
		}

		flag = 0;
		for (int i = 1; i <= m; i++){
			if (now == 3){
				cnt = 1;
				maxx = 0;
			}
			if (i > maxx && c[i] >= cnt){
				c[i] -= cnt;
				maxx = i;
				flag = 1;
				now = 3;
				break;
			}
		}

		if (!flag){
			int num = cnt;
			while (++num <= n){
				bool t = 0;
				for (int i = 1; i <= m; i++){
					if (c[i] >= num){
						c[i] -= num;
						maxx = i;
						cnt = num;
						flag = 1;
						t = 1;
						now = 3;
						break;
					}
				}
				if (t)	break;
			}
		}

		flag = 0;
		for (int i = 1; i <= 50; i++){
			if (c[i] != 0){
				flag = 1;
				break;
			}
		}
		if (!flag){
			cout << "3" << endl;
			return 0;
		}
	}
	return 0;
}
