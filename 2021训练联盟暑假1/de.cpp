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

vector<ll> alls; // 存储所有待离散化的值

// 二分求出x对应的离散化的值
int find(ll x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}

int n;
ll a[100000 + 10];
int cnt[100000 + 10];

int main(){
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		alls.push_back(a[i]);
	}
	
	sort(alls.begin(), alls.end()); // 将所有值排序
	alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素
	
	int ans = n * (n + 1) / 2;
	
	// for(int i = 1, j = 1; i <= n; i++){
		// int id = find(a[i]);
        // cnt[id]++; // 这个数在这个序列中出现了
        // while(j < i && cnt[id] > 1){ // 在序列中，a[i]这个数不能重复出现
            // cnt[id]--;
            // j++;
            // ans--;
        // }
    // }
	
	// 双指针枚举区间
	
	for(int l = 1; l <= n; l++){
		// int before = 0;
		memset(cnt, 0, sizeof(cnt));
		
		int flag = 1;
		
		for(int i = 1; i <= l; i++){
			int id = find(a[i]);
			cnt[id] ++;
			if(cnt[id] > 1){
				flag = 0;
			}
		}
		
		if(!flag) ans--;
		
		int before = find(a[l]);
		
		for(int i = l + 1; i <= n - l + 1; i++){
			cnt[before]--;
			int id = find(a[i]);
			cnt[id] ++;
			if(cnt[id] > 1){
				ans--;
			}
			before = id;
		}
		
	}
	
	cout << ans ;
	
	return 0;
}