#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

struct nope{
    ll cd;
    int c;
    int d;
} summ[5000000 + 10];

bool cmp(nope a, nope b){
    if(a.cd != b.cd) //先按照加和排序，还要保证c d字典序后面
        return a.cd < b.cd;
    if(a.c != b.c)
        return a.c < b.c;
    else
        return a.d < b.d;
}

int n;
int cnt = 0;

// void debug(){
//     for (int i = 0; i <= cnt; i++){
//         cout << summ[i].cd << endl;
//     }
//     cout << endl;
// }

int main(){ //hello
    scanf("%d", &n);
    for (int c = 0; c * c <= n; c++){ // 构建c2 d2
        for (int d = c; d * d + c * c <= n; d++){ //d要从c开始，保证字典序并且不重复
            summ[cnt++] = {c * c + d * d, c, d};
        }
    }

    sort(summ, summ + cnt, cmp);
    // sort(summ + 1, summ + cnt + 1);
    // debug();

    for (int a = 0; a * a <= n; a++){
        for (int b = a; b * b + a * a <= n; b++){ 
            int t = (n - a * a - b * b);
            int l = 0;
            int r = cnt - 1;
            while(l < r){ //我们要求区间右半段的左端点，因为序列是递增的，而且答案要求字典序最小的
                int mid = (l + r) >> 1;
                if(summ[mid].cd >= t)
                    r = mid;
                else
                    l = mid + 1;
            }
            if(summ[l].cd == t){
                printf("%d %d %d %d", a, b, summ[l].c, summ[l].d);
                return 0;
            }
        }
    }
}