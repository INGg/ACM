#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int tr[100000 + 10];
int n, m;
int k, a, b;

int lb(int x){
    return x & -x;
}

void modify(int p, int v){
    for (; p <= n; p += lb(p)){
        tr[p] += v;
    }
}

int query(int p){
    int ans = 0;
    for (; p; p -= lb(p)){
        ans += tr[p];
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        modify(i, x);
    }

    for (int i = 1; i <= m; i++){
        cin >> k >> a >> b;
        if (!k){
            cout << query(b) - query(a - 1) << endl;
        }
        else
            modify(a, b);
    }
    return 0;
}