/*
 * @Author: your name
 * @Date: 2021-03-14 14:30:39
 * @LastEditTime: 2021-03-15 20:37:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \ACM\AC1236.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;

int a[100000 + 10];
int b[100000 + 10];
int c[100000 + 10];
int n;
const int N = 100000 + 5;
ll cnta[100000 + 10]; //统计a数组中某个数对应出现多少次
ll sum_cnta[100000 + 10]; // 统计a数组中某个区域内出现多少数的点缀和
ll cntc[100000 + 10];
ll sum_cntc[100000 + 10]; //同理

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
        cnta[a[i]]++;
        // cout << a[i] << endl;
        // maxa = max(maxa, a[i]);
    } 
    for (int i = 1; i <= n; i++){
        scanf("%d", b + i);
    }
    for (int i = 1; i <= n; i++){
        scanf("%d", c + i);
        cntc[c[i]]++;
        // maxc = max(maxc, c[i]);
    }

    // cout << maxa << endl;
    sum_cnta[0] = cnta[0]; // 注意统计数出现的个数中也要统计0的个数，记得前缀和数组要改变初值！
    for (int i = 1; i <= N; i++){
        sum_cnta[i] = sum_cnta[i - 1] + cnta[i];
        // cout << sum_cnta[i] << endl;
    }
    sum_cntc[0] = cntc[0]; 
    for (int i = 1; i <= N; i++){
        sum_cntc[i] = sum_cntc[i - 1] + cntc[i];
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++){
        // printf("%d %d \n", sum_cnta[b[i] - 1], (sum_cntc[maxc] - sum_cntc[b[i]]));
        ans += (long long)(sum_cnta[b[i] - 1] * (sum_cntc[N] - sum_cntc[b[i]]));
    }
    cout << ans;
    return 0;
}
