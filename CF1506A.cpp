#include <iostream>

using namespace std;

int T;

int main(){
    cin >> T;
    while(T--){
        long long n, m, x;
        cin >> n >> m >> x;
        x--;
        long long r = x % n;
        long long c = x / n;
        // cout << r << " " << c << endl;
        cout << r * m + c + 1 << endl;
    }
    return 0;
}