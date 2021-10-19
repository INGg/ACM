#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#define ll long long
#define re return

using namespace std;

int n;
// int unhappy[100000 + 10];
struct nope
{
    int h;
    ll len; //移动长度
    int index; //上一次位置
    
}a[100000 + 10], temp[100000 + 10];

void merge_sort(int l, int r){
    if(l >= r)
        return;
    int mid = (l + r) >> 1;
    int i = l;
    int j = mid + 1;
    int k = l;

    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    while(i <= mid && j <= r){
        if(a[i].h > a[j].h){
            temp[k++] = a[j++];
        }
        else{
            temp[k++] = a[i++];
        }
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];

    for (int i = l, j = 0; i <= r; i++, j++){
        a[i] = {
            temp[i].h,
            temp[i].len + abs(temp[i].index - i),
            i
        };
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].h;
        a[i].index = i;
    }

    merge_sort(1, n);

    ll summ = 0;
    for (int i = 1; i <= n; i++){
        summ += (a[i].len + 1) * a[i].len / 2;
    }
    cout << summ;
    return 0;
}