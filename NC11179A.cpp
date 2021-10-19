#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#define ll long long
#define ull unsigned long long

using namespace std;

int n, k;
ll s;
ll base[100];
bool st[100];

void init(){
    for (int i = 0; i < 64; i++){
        base[i] = 1 << i;
    }
}

int main(){
    // init();
    cin >> n >> k;
    cin >> s;
    while(k--){
        int x;
        cin >> x;
        st[x - 1] = 1;
    }

    int flag = 1;

    // if((s >> (n - 1)) > 0){
    //     cout << "NO";
    //     return 0;
    // }

    for (int i = n - 2; i >= 0; i--){
        if((s >> i) & 1){
            if(st[i]){
                flag = 0;
                break;
            }
        }
    }

    if(flag)
        cout << "YES";
    else
        cout << "NO";
}