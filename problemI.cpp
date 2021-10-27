#include <algorithm>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn = 1e3 + 7;
const double PI = acos(-1);
int main() {
    int n,m;scanf("%d%d",&n,&m);
    double ans = (2 * m + 2 * m * n) * n / 2; // 所有点到原点的距离 2m * ((1 + n) * n) / 2;
    if(m == 1) ans = 0;
    for(int i = 1;i <= n;i++) { // 当前圆
        double now = 0.0;
        double len = PI * i / m; // 当前圆的弧长：2πr/n
        for(int j = i;j <= n;j++) { // 他的外围圆，固定一个点，去掉对面的点，对面的点肯定走直径
            now = 0.0;
            now += j - i; // 加一个在同一条直线上的
            for (int p = 1; p <= m - 1; p++)
            {                                  // 不在同一条直线上的
                double l1 = len * p + (j - i); // 外围圆先走到内层圆上然后走里面的小弧
                double l2 = i + j; // 走到原点再回来
                now += min(l1,l2) * 2; // 取最小值，并且对称还有一半
            }
            now += i + j; // 对面的点
            if(j == i) ans += now * m; // 同一个圆上一侧只有m个点
            else ans += now * 2 * m; // 不同的圆上每一个点都会这样算一次
        }
    }
    printf("%.10f\n",ans);
    return 0;
}

