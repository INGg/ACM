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

int n, m;
int a[1000 + 10][1000 + 10];
int boomx[1000 + 10];
int boomy[1000 + 10];

int main(){
    cin >> n >> m;
    int boom = 0;
    char c;

    for(int i = 1; i <= n;i++){
        for (int j = 1; j <= m; j++){
            cin >> c;
            if(c == '*'){
                a[i][j] = 1;
                boom++;
                boomx[i]++;
                boomy[j]++;
            }
            else a[i][j] = 0;
        }
        
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(boomx[i] + boomy[j] - a[i][j] == boom){
                cout << "YES" << endl;
                cout << i << " " << j;
                re 0;
            }
        }
    }
    cout << "NO";
    re 0;
}