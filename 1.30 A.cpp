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

int a, b, c;
int n;

int main(){
    cin >> a >> b >> c >> n;
    //容斥
    // n--;
    int x = a + b - c;
    if(n - x > 0 && c <= a && c <= b){
        cout << n - x;
    }
    else{
        cout << "-1";
    }
    re 0;
}