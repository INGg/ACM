// Problem: B. Moamen and k-subarrays
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Code by: ING__
// 
// Edited on 2021-08-09 22:36:51

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
int n, k;
int a[100000 + 10];

vector<int> alls; // 存储所有待离散化的值

// 二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}

int main(){
	cin >> T;
	while(T--){
		cin >> n >> k;
		alls.clear();
		
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			alls.push_back(a[i]);
		}
		
		sort(alls.begin(), alls.end()); // 将所有值排序
		alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素		
		
		
		int cnt = 1; // 有顺序的块
		
		for(int i = 2; i <= n; i++){
			if(find(a[i]) - find(a[i - 1]) == 1){	
				continue;
			}
			else{
				cnt ++;
			}
		}
		
		// cout << cnt << Endl;
		
		if(cnt <= k){
			cout << "YES" << endl;
		}
		else cout << "NO" << Endl;
	}
}