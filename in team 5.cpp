#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

//01背包

int n, h, m; // 生物军团总数，小雒骑士血量和迎娶公主所需要的金币数
int a[2000 + 10];
int g[2000 + 10];
int s[2000 + 10];
//生物军团士兵的攻击力，击杀所得金币数，士兵数量。

//多重背包，看当H最小时，能获得最大的利润够不够
int f[2000 + 10];

int main(){
    scanf("%d%d%d", &n, &h, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d%d%d", a + i, g + i, s + i);
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= s[i]; j++){
            for (int k = h; k >= a[i]; k--){
                f[k] = max(f[k], f[k - a[i]] + g[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; i++){
        ans = max(ans, f[i]);
    }
    if(ans >= m){
        printf("YES ");
    }
    else{
        printf("NO ");
    }
    printf("%d", ans);
    return 0;
}