#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#define ll long long
#define re return

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    int a[1000];
    int summ = 0;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        summ += a[i];
    }

    int av = ((double)(1.0 * summ / (n * 1.0)) + 0.5);
    sort(a + 1, a + 1 + n);
    int i = 1;
    while(av < 5){
        if(a[i] == 5)
            break;
        summ = summ - a[i] + 5;
        // cout << summ << endl;
        av = ((double)(1.0 * summ / (n * 1.0)) + 0.5);
        // cout << av << endl;
        i++;
        ans++;
    }
    cout << ans;
    re 0;
}