#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define re return
#define ll long long

using namespace std;

int k;
int n;
int h[100000 + 10];
int maxx = -1;

// 如果H(k+1)>E，那么机器人就失去H(k+1)-E的能量值，否则它将得到E-H(k+1)的能量值。

bool check(ll e){
    for (int i = 0; i <= n - 1; i++){
        if(e < 0)
            return false;
        if(e >= maxx){ //如果比最大值还要大了，那么他会一直得到能量，使得能量一直增大
            return true;
        }
        if(h[i + 1] > e)
            e = e - (h[i + 1] - e);
        else{
            e = e + (e - h[i + 1]);
        }
    }
    if(e < 0)
        re false;
    else
        re true;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(false);
    cin >> n;
    int l = 0;
    int r = -1;
    for (int i = 1; i <= n; i++){
        scanf("%d", h + i);
        r = max(r, h[i]);
        l = min(l, h[i]);
        maxx = max(maxx, h[i]);
    }

    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << '\n';

    re 0;
}