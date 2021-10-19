#include <iostream>
#define ll long long

using namespace std;

int T;
int n;

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        n++;
        ll ans = 0;
        ll v = (n + 1) / 2;
        ans = n - v;
        v = (n - 1 + 2) / 3;
        if(v % 2 == 0) v++;
        if(n % 2 == 1){
            ans += (n - v) / 2;
        }
        else ans += (n - v) / 2 + 1;
        cout << ans << endl;
    }
}