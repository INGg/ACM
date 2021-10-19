#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int weight[100001] = { 0 };

bool calc(int n, int mid)
{
	int a = 0, b = 0;

	for (int i = 1; i <= n; i++)
	{
		if (weight[i] < mid)
		{
			a += weight[i];
		}
		else if (weight[i] > mid)
		{
			b += weight[i];
		}
	}

	if (a >= b)	return true;
	else return false;
}

int main()
{
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &weight[i]);
	}

	sort(weight + 1, weight + n + 1);

	int l, r, mid;
	l = weight[1];
	r = weight[n];

	while (l < r)
	{
		mid = (l + r) / 2;
			
		if (calc(n, mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}

	cout << l << endl;

	return 0;
}