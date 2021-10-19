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

// ai = 0，休假第i天健身房关闭，不进行比赛;
// ai = 1，休假第i天健身房关闭，但比赛进行;
// ai = 2，休假第i天健身房开放，不进行比赛;
// ai = 3，休假第i天健身房开放并进行比赛。

// 找出Vasya休息的最少天数

int n;
int a[100 + 10];
int f[100 + 10][3]; //在截至到某天中的最长休息天数

int main(){
    cin >> n;
    for (int i = 1; i <= 100; i++){
        f[i][0] = f[i][1] = f[i][2] = 999999;
    }
    for (int i = 1; i <= n; i++)
            cin >> a[i];
    for (int i = 1; i <= n; i++){

        f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;

        if(a[i] == 1 || a[i] == 3)
            f[i][1] = min(f[i - 1][0], f[i - 1][2]);

        if(a[i] == 2 || a[i] == 3)
            f[i][2] = min(f[i - 1][0], f[i - 1][1]);

    }

    cout << min(f[n][0], min(f[n][1], f[n][2]));
    re 0;
}