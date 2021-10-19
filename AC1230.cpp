#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int n;
ll a[100000 + 10];
int k;
ll s[100000 + 10];
vector<ll> wei[100000 + 10];

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = (s[i - 1] % k + a[i] % k) % k;
        wei[s[i]].push_back(i);
    }

    ll x = wei[0].size();
    ll cnt = x * (x + 1) / 2;

    for (int i = 1; i <= k; i++){
        x = wei[i].size();
        cnt += ((x - 1) * x / 2);
    }

    cout << cnt;
    return 0;
}