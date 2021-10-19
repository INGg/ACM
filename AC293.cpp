// Problem: 蒙德里安的梦想
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/293/
// Memory Limit: 64 MB
// Time Limit: 5000 ms
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
#include <bitset>
#include <sstream>
#define ll long long
#define re return
#define Endl "\n"
#define endl "\n"

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

const int M = (1 << 12) + 10;
const int N = 11 + 10;

int n, m;
int f[N][M];
bool st[M];

int main()
{

	while (cin >> n >> m, n || m)
	{
		for(int i = 0; i < 1 << n; i++){
			int cnt = 0;
			st[i] = 1;
			for(int j = 0; j < n; j++){
				if(i >> j & 1){
					if(cnt % 2 == 1) st[i] = 0;
					cnt = 0;
				}
				else cnt++;
			}
			if(cnt % 2 == 1) st[i] = 0;
		}

		memset(f, 0, sizeof f);
		f[0][0] = 1;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < (1 << n); j++)
			{
				// f[i][j] = 0;
				for (int k = 0; k < (1 << n); k++)
				{
					if (((j & k) == 0) && (st[j | k]))
					{
						f[i][j] += f[i - 1][k];
					}
				}
			}
		}

		cout << f[m][0] << endl;
	}
}