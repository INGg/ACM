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
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define re return
#define pb push_back
#define Endl "\n"
#define endl "\n"
// #define x first
// #define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int sgn(double x){
    if(fabs(x) < eps)
        return 0;
    if(x < 0)
        return -1;
    else
        return 1;
}

struct Point{
    double x;
    double y;

    Point(){}
    Point(double _x, double _y){
        x = _x;
        y = _y;
    }
    void input(){
        scanf("%lf%lf", &x, &y);
    }

    void output(){
        printf("%.2lf %.2lf\n", x, y);
    }

    bool operator == (Point b)const{
        return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
    }

    bool operator < (Point b)const{
        return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0 : x < b.x;
    }

    Point operator -(const Point &b)const{
        return Point(x-b.x, y-b.y);
    }
    // 叉积
    double operator ^(const Point &b)const{
        return x * b.y - y * b.x;
    }
    //点积
    double operator *(const Point &b)const{
        return x * b.x + y * b.y;
    }
    //返回长度
    double len(){
        return hypot(x,y);//库函数
    }
    //返回长度的平方
    double len2(){
        return x*x + y*y;
    }

}p[N], h[N];

double cross(Point a, Point b) {return a.x * b.y - b.x * a.y;} // 叉积 
double area(Point a, Point b, Point c) {return cross(b-a, c-a);} // 判向 

double get_dis(Point a, Point b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int n;
int stk[N];
bool st[N];

bool check(){
    for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(sgn(area(p[i], p[j], p[k])) == 0)
					return 1;
			}
		}
	}
	return 0;
}

void debug(){
    for (int i = 1; i <= n; i ++){
        cout << p[i].x << " " << p[i].y << Endl;
    }
}

int main(){
    string s;
    vector<int> v;
    getline(cin, s);
    istringstream is(s);
    int inter;
    char ch;
    while (is >> inter)
    {
         v.push_back(inter);
         is >> ch;
    }

    if(v.size() % 2 != 0){
        cout << "ERROR";
        return 0;
    }

    

    // for(int i=0;i<v.size();i++)
    //     cout<<v[i]<<" ";
    // cout<<endl;

    int cnt = 0;
    for (int i = 0; i < v.size(); i += 2){
        p[++cnt] = {(double)v[i], (double)v[i + 1]};
    }

    n = cnt;
    if(check()){
        cout << "ERROR";
        return 0;
    }

    // debug();

    int tp = 0;
    sort(p + 1, p + 1 + n);

    // debug();

    stk[++tp] = 1;

    for (int i = 2; i <= n; i++){
        while(tp >= 2 && ((p[stk[tp]] - p[stk[tp - 1]]) ^ (p[i] - p[stk[tp]])) <= 0)
            st[stk[tp--]] = 0;
        st[i] = 1;
        stk[++tp] = i;
    }
    int tmp = tp;

    for (int i = n - 1; i > 0; i--){
        if(!st[i]){
            while(tp > tmp && ((p[stk[tp]] - p[stk[tp - 1]]) ^ (p[i] - p[stk[tp]])) <= 0)
                st[stk[tp--]] = 0;
            st[i] = 1;
            stk[++tp] = i;
        }
    }

    for (int i = 1; i <= tp; ++i)  // 复制到新数组中去
        h[i] = p[stk[i]];
    int num = tp - 1;

    // debug();
    // cout << num << endl;

    if(num < 3){
        cout << "ERROR";
        return 0;
    }

    Point cc = {0,0};
    int k = 1;
    for (int i = 2; i <= num; i++){
        if(get_dis(p[i],cc) < get_dis(p[k],cc))
            k = i;
    }
    for (int i = 1; i <= num; i++){
        printf("%.0lf,%.0lf",p[stk[k]].x, p[stk[k]].y);
        if(i!=num)
            printf(",");
        k--;
        if(k == 0)
            k = num;
    }
}