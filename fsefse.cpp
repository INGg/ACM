#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
using namespace std;
#define eps 1e-6
const int N = 5e5+5;
int n;
double x[N],y[N],z[N];
struct POINT
{
    double x,y;
};
POINT t1[N],t2[N],t3[N];
double getd(POINT a,POINT b) //求两个点之间的长度
{
    return  sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y) * (a.y-b.y) );
}
POINT getO(POINT p1,POINT p2,POINT p3) //已知三点求圆心
{
    POINT ans;
    double a = p2.x - p1.x;
    double b = p2.y - p1.y;
    double c = p3.x - p2.x;
    double d = p3.y - p2.y;
    double e = (p2.x * p2.x) + (p2.y * p2.y) - (p1.x * p1.x) - (p1.y * p1.y);
    double f = (p3.x * p3.x) + (p3.y * p3.y) - (p2.x * p2.x) - (p2.y * p2.y);
    ans.x = (f*b - e*d) / (c*b - a*d) /2.0;
    ans.y = (a*f - e*c) / (a*d - b*c) /2.0;
    return ans;
}
double R;
void mincir() //求最小圆
{
    // O相当于圆心，R相当于半径
    POINT O = t1[1]; //选择第一个点
    R = 0;
    for(int i=1;i<=n;i++) //点是一个一个增加的
    {
        if(getd(t1[i],O)-R > eps) //如果两点之间的距离大于R，则说明这个点在圆之外，就进入下一步，且i这个点一定在新圆的边界上
        {
            O = t1[i];
            R = 0; //R变为零，接下来，任何一个点与O点之间的距离都大于0，所以一定进行下一步
            for (int j=1;j<i;j++) //在[1,i)之间的点进行判断，看是否在范围内
            {
                if(getd(t1[j],O)-R > eps) //如果当前点不在范围内，找到第二个点在新圆的边界上
                {
                    //O 变成两个边缘点的中点 , R变成以两个边缘点为直径的半径，即以这两个点为直径做圆
                    O = (POINT){(t1[i].x + t1[j].x)/2.0 , (t1[i].y + t1[j].y)/2.0};
                    R = getd(t1[i],t1[j])/2.0;

                    for (int k=1;k<j;k++)
                    {
                        if(getd(t1[k],O)-R >eps) //如果出现第三个点不在两个边缘点组成的圆上，直接构成新的圆，更新 新的半径。
                        {
                            O = getO(t1[i], t1[j], t1[k]);
                            R = getd(t1[i],O); //求出半径
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf %lf %lf",&x[i],&y[i],&z[i]);
        //t1表示xy面
        t1[i].x=x[i];
        t1[i].y=y[i];
    }
    random_shuffle(t1+1,t1+1+n); //将点打乱
    mincir();
    cout << R << endl;
    double ans = R;
    for (int i=1;i<=n;i++)
    {
        //表示xz面
        t1[i].x=x[i];
        t1[i].y=z[i];
    }
    random_shuffle(t1+1,t1+1+n); //将点打乱
    mincir();
    cout << R << endl;
    ans = min(ans,R);

    for (int i=1;i<=n;i++)
    {
        //t3表示yz面
        t1[i].x=y[i];
        t1[i].y=z[i];
    }
    random_shuffle(t1+1,t1+1+n);
    mincir();
    cout << R << endl;
    ans = min(ans , R);
    printf("%.4lf\n",ans*2);
    return 0;
}