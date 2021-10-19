#include <iostream>
#define ll long long

using namespace std;

int main(){
    int x;
    int y;
    cin >> x >> y;
    if(abs(x) <= y){
        ll n = y;
        cout << (2 * n - 1) * (2 * n) + abs(x - (-n));
    }
    else if(abs(y) <= x){
        ll n = x;
        cout << (2 * n) * (2 * n) + abs(y - n);
    }
    else if(abs(x) <= abs(y) + 1 && y < 0){
        ll n = abs(y);
        cout << (2 * n) * (2 * n + 1) + abs(x - (n));
    }
    else{
        ll n = abs(x);
        cout << (2 * n - 1) * (2 * n - 1) + abs(y - 1 - (-n));
    }
    return 0;
}