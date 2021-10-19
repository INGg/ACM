#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

int n;
ll a[200000 + 10];
ll summ[200000 + 10];
ll wei[200000 + 10];

//dp以i结尾的最大的t

void debug(){
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << summ[i] << " ";
    }
    cout << endl << endl;

    for (int i = 1; i <= n; i++){
        cout << wei[i] << " ";
    }
    cout << endl << endl;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld", a + i);
        summ[i] = (summ[i - 1] + a[i] % n) % n;
        wei[summ[i]] = i; //记录1-n每个数最后的出现位置
    }
    debug();
    ll ans = -1;
    for (ll i = 1; i <= n; i++){
        if(summ[i] == 0){
            ans = max(ans, i);
        }
        else {
            ans = max(ans, wei[summ[i]] - i); //这个数最后出现的位置，  
            // wei[summ[i]] = i;
        }
    }
    cout << ans;
    return 0;
}