#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

int tr[100000 + 10];
int y[100000 + 10];
ll g[100000 + 10];
ll l[100000 + 10];
int n;

int lb(int x){
    return x & -x;
}

int query(int p){
    int ans = 0;
    for (; p;p -= lb(p)){
        ans += tr[p];
    }
    return ans;
}

void modify(int i, int v){
    for (; i <= n; i += lb(i)){
        tr[i] += v;
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> y[i];
    }
}