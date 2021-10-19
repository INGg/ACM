#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#define ll unsigned long long
#define re return

using namespace std;

void work(){
    int n, k;
    cin >> n >> k;
    int x = n / k;
    int a = 0;
    int b = 0;
    if(x % 2 == 1){
        int y = n % k;
        if(y % 2 == 0){
            b = 1;
        }
        else
            a = 1;
    }
    else{
        int y = n % k;
        if(y % 2 == 0){
            a = 1;
        }
        else
            b = 1;
    }
    if(a)
        cout << "yo xi no forever!" << endl;
    else
        cout << "ma la se mi no.1!" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        work();
    }
    re 0;
}