#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    double n;
    cin >> n;
    int t = 0;
    if(n < 0){
        t = 1;
        n = -n;
    }
    double l = 0;
    double r = n;
    double mid;
    while(r - l > 1e-8){
        mid = (l + r) / 2;
        if(mid * mid * mid <= n)
            l = mid;
        else
            r = mid;
    }
    if(!t)
        printf("%.6lf", mid);
    else printf("-%.6lf", mid);
    return 0;
}