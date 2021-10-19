#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#define ll long long
#define re return

using namespace std;

struct nope
{
    ll p;
    ll c;
    ll id;
    ll ans;
}a[100000 + 10];

ll n, k;

// priority_queue<int> q;

bool cmp1(nope a, nope b){ //按力量从小到大
    return a.p < b.p;
}

bool cmp2(nope a, nope b){ //编号从小到大
    return a.id < b.id;
}

int main(){
    cin >> n >> k;
    for (ll i = 1; i <= n; i++){
        cin >> a[i].p;
        a[i].id = i;
    }

    for (ll i = 1; i <= n; i++){
        cin >> a[i].c;
    }

    if(k == 0){
        for (ll i = 1; i <= n; i++){
            cout << a[i].c << " ";
        }
        return 0;
    }

    sort(a + 1, a + n + 1, cmp1);

    ll max_sum = a[1].c; //存前k个中最小的那个，来更新答案
    ll min_c[200];
    min_c[1] = a[1].c;
    a[1].ans = a[1].c; //没得杀

    for (ll i = 2; i <= k + 1;  i++){ //前k个只能杀他前面的，
        a[i].ans = a[i - 1].ans + a[i].c;
        if(i != k + 1){
            min_c[i] = a[i].c; //前k个的值
            max_sum += a[i].c; //前k个的和
        }
    }

    // max_sum -= a[k + 1].c; //杀前k个的最大和
    sort(min_c + 1, min_c + k + 1);

    for (ll i = k + 2; i <= n; i++){
        if(min_c[1] < a[i - 1].c){ //有没有必要杀第i - 1个，i个是他自己不能杀；杀i-1的收益打还是不杀他的收益大
            max_sum = max_sum - min_c[1] + a[i - 1].c;
            min_c[1] = a[i - 1].c;
            sort(min_c + 1, min_c + 1 + k);
        }
        a[i].ans = max_sum + a[i].c;
    }

    sort(a + 1, a + 1 + n, cmp2);
    for (ll i = 1; i <= n; i++){
        cout << a[i].ans << " ";
    }
    return 0;
}