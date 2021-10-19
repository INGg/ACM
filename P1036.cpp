#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int isPrime(int n){
    if(n == 0 || n == 1){
        return 0;
    }
    if(n == 2)
        return 1;
    for (int i = 2; i * i <= n; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int n, k;
    //利用二进制表示每一个元素的使用情况
    int a[25];
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    int num = 1 << (n);
    for (int i = 0; i < num; i++){
        if(__builtin_popcount(i << 1) == k){
            int summ = 0;
            for (int j = 1; j <= n; j++){
                if((i << 1) & (1<<j))
                    summ += a[j];
            }
            if(isPrime(summ))
                ans++;
        }
    }
    cout << ans;
    return 0;
}