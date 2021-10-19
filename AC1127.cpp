#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define re return

using namespace std;

int n, k;

struct nope{
    int h;
    int w;
} a[100000 + 10];

bool check(int x){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        // if(a[i].h >= x && a[i].w >= x){
            cnt += (a[i].h / x) * (a[i].w / x);
        // }
    }
    if(cnt >= k)
        return true;
    else
        return false;
}

int main(){
    cin >> n >> k;
    int r = 1;
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &a[i].h, &a[i].w);
        r = max(r, min(a[i].h, a[i].w));
    }

    int l = 1;
    
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << r << endl;
    re 0;
}