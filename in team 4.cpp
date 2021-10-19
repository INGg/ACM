#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long

const int MAXN = 100000 + 10;

using namespace std;



ll a, b; //总攻击力

int main(){
    int c,d;
int n;
ll h[MAXN];

int m;
ll x[MAXN];
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &c,&d);
        h[i] = c;
        a += d;
    }
    scanf("%d", &m);
    
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &c,&d);
        x[i] = c;
        b += d;
    }

    int cnt_n = 1;
    int cnt_m = 1;

    while(cnt_m != m && cnt_n != n){
        int aa = a;
        int bb = b;
        while(cnt_m != m){
            if(x[cnt_m] > aa){
                 x[cnt_m] -= aa;
                    break;
            }
            else{
                aa -= x[cnt_m];
                x[cnt_m++] = 0;
            }
        }

        while(cnt_n != n){
            if(h[cnt_n] > bb){
                 h[cnt_n] -= bb;
                    break;
            }
            else{
                bb -= h[cnt_n];
                h[cnt_n++] = 0;
            }
        }
    }

    cout << cnt_n << " " << cnt_m << endl;
    if(!x[m] && h[n]){
        cout << "NIGHTMARE";
    }
    else if(x[m] && !h[n]){
        cout << "MOOMOO";
    }
    else{
        cout << "PRINCESS";
    }
    return 0;
}