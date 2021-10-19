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

int n;

int num(int x){
    int t = 0;
    while(x){
        t = t + x % 10;
        x /= 10;
    }
    return t;
}

int main(){
    cin >> n;
    int x = num(n);
    int i;
    for (i = n + 1; x != num(i); i++)
        ;
    cout << i;
    re 0;
}