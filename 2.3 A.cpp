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

int n, m, k; //村子里的房屋数量，女孩住的房子，和Zane拥有的钱的数量(美元)。
// int a[105];

struct nope{
    int len;
    int w;
    int id;
} a[105];

//每个房子间隔十米

bool cmp(nope a,nope b){
    return a.len < b.len;
    return a.w < b.w;
}

int main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].w;
        a[i].id = i;
    }

    for (int i = 1; i <= n; i++){
        a[i].len = abs(a[i].id - m);
    }

    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++){
        if(a[i].w != 0 && a[i].id != m){
            if(a[i].w <= k){
                cout << a[i].len * 10;
                return 0;
            }
        }
    }
}