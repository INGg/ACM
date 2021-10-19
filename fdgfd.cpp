#include <iostream>

using namespace std;

const int N = 1e4 + 10;

int n, m;
bool st[N];
int a[N];

int main(){
    cin >> n >> m;

    while(m--){
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++){
            st[i] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++){
        if(!st[i])
            ans++;
    }

    cout << ans << endl;
}