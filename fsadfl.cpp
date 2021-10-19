#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-12;
#define Point pair<double,double>
#define x first
#define y second

int sign(double x)
{
	if(fabs(x) < eps) return 0;
	return x<0 ? -1:1;
}
Point operator-(Point a, Point b) {return {a.x-b.x, a.y-b.y};} // 向量 
double cross(Point a, Point b) {return a.x * b.y - b.x * a.y;} // 叉积 
double area(Point a, Point b, Point c) {return cross(b-a, c-a);} // 判向 
double get_dis(Point a, Point b)
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int n,top;
bool vis[110];
Point pt[10010];
int stk[10010];
void Graham()
{
	sort(pt+1, pt+1+n);
	top = 0;
	int ck;
	for(int i=1;i<=n;i++)
	{
		while(top>1 && (ck = sign(area(pt[stk[top-1]], pt[stk[top]], pt[i]))) <= 0)
		{
			vis[stk[top]] = 0;
			top--;
		}
		stk[++top] = i;
		vis[i] = 1;
	}
	vis[1] = 0;
	for(int i=n;i>=1;i--)
	{
		if(vis[i]) continue;
		while(top>1 && sign(area(pt[stk[top-1]], pt[stk[top]], pt[i])) <= 0)
			top--;
		stk[++top] = i;
	}
	if(stk[top]==1) top--;
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(sign(area(pt[i], pt[j], pt[k])) == 0)
					return 1;
			}
		}
	}
	return 0;
}
void solve()
{
	n = 0;
	char c;
	double x,y;
	while(scanf("%lf,%lf",&x, &y)!=EOF)
	{
		pt[++n] = {x,y};
		scanf("%c",&c);
	}
	
	if(check())
	{
		cout<<"ERROR"<<endl;
        cout << 1 << endl;
        return ;
	}
	Graham();
    cout << top << endl;
    if(top!=n)
		cout<<"ERROR"<<endl;
	else
	{
		Point cc = {0,0};
		int k = 1;
		for(int i=2;i<=top;i++)
		{
			if(get_dis(pt[i],cc) < get_dis(pt[k],cc))
				k = i;
		}
		for(int i=1;i<=top;i++)
		{
			printf("%.0lf,%.0lf",pt[stk[k]].x, pt[stk[k]].y);
			if(i!=top) printf(",");
			k--;
			if(k==0) k = top;
		}
	}
}
int main()
{
	solve();
	return 0;
}

