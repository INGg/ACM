#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define ll long long
#define re return

using namespace std;

int T;

int main(){
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for (int cnt = 1; cnt <= n; cnt++){
            cout << 4 * n - cnt * 2 << " ";
        }
        cout << endl;
    }
    re 0;
}