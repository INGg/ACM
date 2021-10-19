#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int T, n;
char str[N];
signed main() {
    cin >> T;
    while (T --) {
        int flag = 0;
        cin >> n >> str + 1;
        for (int i = 1; i <= n; i ++) {
            if (str[i] == '0') {
                flag = 1;
                if (i <= n / 2) {
                    cout << i << " " << n << " " << i + 1 << " " << n << endl;
                } else {
                    cout << 1 << " " << i << " " << 1 << " " << i - 1 << endl;
                }
                break;
            }
        }
        if (!flag) {
            cout << 2 << " " << n << " " << 1 << " " << n - 1  << endl;
        }
    }
}
