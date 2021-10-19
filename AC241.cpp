#include <iostream>
#include <cstring>
#define ll long long

using namespace std;

int n;
const int N = 200000 + 10;

int tr[200000 + 10];

int lb(int b){
    return b & (-b);
}

int query(int p){
    int ans = 0;
    for (; p; p -= lb(p))
    {
        ans += tr[p];
    }
    return ans;
}

void modify(int i, int v){
    for (; i <= n; i += lb(i)){
        tr[i] += v;
    }
}

int y[N];
ll g[N];
ll l[N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> y[i];
    }

    for (int i = 1; i <= n; i++){
        modify(y[i], 1);
        l[i] = query(y[i] - 1);
        g[i] = query(n) - query(y[i]);
    }

    memset(tr, 0, sizeof(tr));

    ll ansv = 0;
    ll answ = 0;
    for (int i = n; i >= 1; i--){
        ansv += g[i] * (query(n) - query(y[i]));
        answ += l[i] * query(y[i] - 1);
        modify(y[i], 1);
    }
    cout << ansv << " " << answ;
    return 0;
}