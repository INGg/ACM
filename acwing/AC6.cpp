// Problem: 多重背包问题 III
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/6/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-24 16:05:22

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#define ll long long
#define re return
#define Endl "\n"
#define endl "\n"

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
int q[20010];
int f[20010];
int g[20010];

int main(){
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		memcpy(g, f, sizeof(f));
		
		int s, v, w;
		cin >> v >> w >> s;
		for(int j = 0; j < v; j++){ // 枚举余数
			int hh = 0;
			int tt = -1;
			
			for(int k = j; k <= m; k += v){
				if(hh <= tt && q[hh] < k - s * v) // 单调队列，如果超过范围了，就要及时弹出
                    // 我们这里的范围就是前 s 个
                    // 但是我们这里因为是枚举的余数，所以要进行变换，即看看现在我要放进队列的是哪几个 v ，现在的区间范围是多少
					hh++;
				while(hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w)
                    // 我们里面存的都是加过 w 的，我们要把它们减回来来比较在队列里是不是应该加回来
                    // 我们要减回来才能进行同一相对大小的比较
                    // 为什么要减参考最后一个链接前面三四端
					tt--;
				if(hh <= tt)
					f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w);
					// 看中间空余了多少的体积；我们在更新的时候，我们要加的实际上应该是 (k - j) / v + w
					// 但是我们在前面已经加过了这些，我们如果这时候再加这些就重复了
					// 所以我们实际上要加的只是中间没加过的而已
				q[++tt] = k;
			}
		}
	}
	
	cout << f[m];
	
	return 0;
}