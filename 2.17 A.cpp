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

int n;
int a[1000 + 10];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    int ans = 0;
    for (int i = 2; i <= n; i++){
        ans += a[i] - a[i - 1] - 1;
    }

    cout << ans;

    re 0;
}