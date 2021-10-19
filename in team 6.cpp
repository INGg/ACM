#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

int n;
long long ksm(long a,long b,long p) {
    long long ans=1;
    while(b){
        if (b&1) ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    } 
    return ans;
} 

int main(){
    cin >> n;
    cout << ksm(2, n, 1000000007);
    return 0;
}