#include <iostream>

using namespace std;

int n, m;
int v[1000 + 10];
int w[1000 + 10];
int f[1000 + 10];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = m; j >= v[i]; j--){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m];
    return 0;
}