#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#define ll long long

using namespace std;

typedef pair<int,int>p;

map<p, int> m;  //存每一对的男女关系


int aa[200000 + 10];
int bb[200000 + 10];
int A[200000 + 10]; //存某个男的在组合中出现了多少次
int B[200000 + 10]; //存某个女的在组合中出现了多少次

int n;

int main(){
    int t;
    cin >> t;
    ll a, b, k;

    while(t--){
        cin >> a >> b >> k;
        for (ll i = 1; i <= k; i++){
            cin >> aa[i];
        }
        for (ll i = 1; i <= k; i++){
            cin >> bb[i];
        }

        for (ll i = 1; i <= k; i++){
            m[p(aa[i],bb[i])]++;
            A[aa[i]]++;
            B[bb[i]]++;
        }
        ll ans = 0;
        for (ll i = 1; i <= k; i++){ //细节：不用到k，到k还咋枚举下一个
            m[p(aa[i],bb[i])]--;
            A[aa[i]]--;
            B[bb[i]]--; // 避免算上当前枚举的自己这个，以及后面不要被前面算过的所干扰   
            ans += k - i - A[aa[i]] - B[bb[i]] + m[p(aa[i],bb[i])]; // 不要想当然以为这个aa[i]是每个人，他指的是包含有这aa[i]编号的人的对数有多少
        }
        printf("%lld\n", ans);
        m.clear();
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
    }
    return 0;
}