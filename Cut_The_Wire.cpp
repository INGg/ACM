#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 200010;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		//奇数的电线:3x+1>n   x>(n-1)/3
		LL res = 0;
		int x = (n - 1) / 3;//分界线
		int cnt1 = 0;
		if (n & 1) cnt1 = (n - x + 1) / 2;//中间有多少个奇数
		else cnt1 = (n - x) / 2;
		res += cnt1;

		int cnt2 = (n + 1) / 2;//偶数个数
		res += cnt2;

		printf("%lld\n", res);
	}
	return 0;

}
