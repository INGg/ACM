#include <iostream>
#include <cstdio>
#define ll unsigned long long

using namespace std;

ll n, ans;

int main(){
    cin >> n;
    cout << n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
    return 0;
}