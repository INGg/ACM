#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[100000 + 10];

void quick_sort(int q[], int l, int r){
    if(l >= r)
        return;

    int i = l - 1;
    int j = r + 1;
    int x = q[(l + r) / 2];
    while(i < j){
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if(i < j)
            swap(q[i], q[j]);
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    quick_sort(a, 1, n);
    for (int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}