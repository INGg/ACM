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
#include <vector>
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

priority_queue<int> q;
vector<int> v;

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

    sort(a + 1, a + n + 1, cmp1);

    a[1].ans = a[1].c;
    q.push(a[1].c);
    // v.push_back(a[1].c);
    for(int i = 2; i <= n; i++){
        ll y = q.size();
        ll t = min(k, y);
        a[i].ans = a[i].c;
        for (int j = 1; j <= t; j++){
            int x = q.top();
            q.pop();
            v.push_back(x);
        }
        for (int j = 0; j < v.size(); j++)
        {
            a[i].ans += v[j];
            q.push(v[j]);
        }
        v.clear();
        q.push(a[i].c);
    }

    sort(a + 1, a + 1 + n, cmp2);
    for (ll i = 1; i <= n; i++){
        cout << a[i].ans << " ";
    }
    return 0;
}