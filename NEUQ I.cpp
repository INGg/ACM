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

ll pow22[20];

void init(){
    pow22[1] = 1;
    for(int i = 2; i <= 15; i++){
		pow22[i] = pow22[i - 1] * 2 + 1;
	}
}

void work(){
    ll n;
    cin >> n;
    for(int i = 2; i <= 15; i++){
        if(n % pow22[i] == 0){
            cout << "YE5" << endl;
            return;
        }
        else continue;
    }
    cout << "N0" << endl;
}

int main(){
    int t;
    cin >> t;
    init();
    while(t--){
        work();
    }
    re 0;
}