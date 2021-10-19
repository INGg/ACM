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

int a[200000 + 10];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        int l = i + 1;
        int r = n;
        int val = a[i] * 2;
        int y = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a[mid] <= val){
                y = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (y != -1)
            ans += y - i;
    }
    cout << ans;
    re 0;
}