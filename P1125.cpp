#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[30];

int isPrime(int n){
    if(n == 1 || n == 0)
        return 0;
    if(n == 2)
        return 1;
    for (int i = 2; i * i <= n; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    char s[200];
    cin >> s;
    int l = strlen(s);
    for (int i = 0; i < l; i++){
        a[s[i] - 'a']++;
    }
    sort(a, a + 26);
    int t;
    for (t = 0; a[t] == 0; t++)
        ;
    // cout << t << endl;
    if(isPrime(a[25] - a[t])){
        cout << "Lucky Word" << endl;
        cout << a[25] - a[t];
    }
    else{
        cout << "No Answer" << endl;
        cout << "0";
    }
    
    return 0;
}