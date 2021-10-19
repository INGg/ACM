#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define ll long long
#define re return

using namespace std;

int n, m, k;
int a[1000000 + 10];
bool hole[1000000 + 10];

// void swap1(int a,int b){
//     int t;
//     t = a;
//     a = b;
// }

int main(){
    scanf("%d%d%d", &n, &m, &k);
    // cin >> n >> m >> k;
    a[1] = 1;
    int keng;
    for (int i = 1; i <= m; i++){
        scanf("%d", &keng);
        // cin >> keng;
        hole[keng] = 1;
    }

    int x, y;
    int t = 0; //已经吊洞
    int ans = 1;
    for (int i = 1; i <= k; i++){
        // cin >> x >> y;
        scanf("%d%d", &x, &y);
        // swap(x, y);
        if(!a[x] && !a[y])
            continue;
        if(!t){
            if(hole[x] && a[x]){ //如果一开始就在洞里
                t = 1;
                ans = x;
                continue;
            }
            if(hole[y] && a[y]){
                t = 1;
                ans = t;
                continue;
            }
            swap(a[x], a[y]);
            if(hole[y] && a[y]){
                t = 1;
                ans = y;
                continue;
            }

            if(hole[x] && a[x]){
                t = 1;
                ans = x;
                continue;
            }

            if(a[x]){
                ans = x;
                continue;
            }
            if(a[y]){
                ans = y;
                continue;
            }
        }
    }

    // if(t){
        // cout << ans << endl;
    // for (int i = 1; i <= n; i++){
        // if(a[i]){
            printf("%d\n", ans);
            // break;
        // }
    // }
        
    // }
        re 0;
}

// 3 1 2
// 1
// 1 2
// 2 3