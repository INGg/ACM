#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[1000 + 10];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        if(a[i - 1] < a[i] && a[i] > a[i + 1]){
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}