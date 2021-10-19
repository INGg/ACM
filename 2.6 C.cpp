#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 15000000 + 10;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int prime[MAXN]; //也就4k来个质数
bool isPrime[MAXN];
int cnt_prime = 0;
void make_prime(){
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2; i <= MAXN; i++){
        if(isPrime[i])
            prime[++cnt_prime] = i;
        for (int j = 1; j <= cnt_prime && prime[j] * i <= MAXN; j++){
            isPrime[prime[j] * i] = 0;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int n;
int a[300000 + 10];
int num[MAXN]; //质因数出现的次数


int main(){
    make_prime();
    scanf("%d", &n);
    int maxx = -1;
    int g = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);

        if(!g)
            g = a[i];
        else
            g = gcd(g, a[i]);
    }
    
    int ans = n;
    
    for (int i = 1; i <= n; i++){
        a[i] /= g;
        num[a[i]]++;
        maxx = max(maxx, a[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= cnt_prime; i++){
        int cnt1 = 0;
        int p = prime[i];
        for (int j = p; j <= maxx; j += p){
            cnt1 += num[j]; //类似埃筛的套路，看看包含最小质因子的有几个
        }
        cnt = max(cnt, cnt1);
    }

    if(cnt){
        cout << ans - cnt;
    }
    else
        cout << -1;

    return 0;
}