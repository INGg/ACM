#include <iostream>
#define re return

using namespace std;

int c[500000 + 10]; //树状数组，以x结尾的，长度为2^k次方的区间和
int t;
int x, k ,y2;
int a[500000 + 10];
int s[500000 + 10];
int n, m;

int lb(int x){
    return x & (-x);
}

void modify(int p, int v){ //在p的位置上增加v，子节点找父节点
    for (; p <= n; p += lb(p)){
        c[p] += v;
    }
}

int query(int p){ //查询p位置的前缀和，父节点找子节点
    int ans = 0;
    for (; p; p -= lb(p)){
        ans += c[p];
    }
    return ans;
}



int main()
{
    // getline(cin, s);
    
    scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		// modify(i, a);
	}
	for (int i = 1; i <= n; i++){
		c[i] = s[i] - s[i - lb(i)];
	}
		//ce shi cout << "aeq";
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &t);
			if (t == 1)
			{
				scanf("%d%d", &x, &k);
				modify(x, k);
			}
			if (t == 2)
			{
				scanf("%d%d", &x, &y2);
				int ans = query(y2) - query((x - 1));
				printf("%d\n", ans);
			}
		}
	return 0;
}