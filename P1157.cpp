#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

int n;
int r;
int a[25];

int main(){
    cin >> n >> r;
    for (int i = 1; i <= 25; i++){
        a[i] = i;
    }
    int num = 1 << n;
    string ans[25];
    int cnt = 0;
    for (int i = 0; i < num; i++){
        if(__builtin_popcount(i) == r){
            cnt++;
            for (int j = 1; j <= n; j++){
                if((i << 1) & (1 << j)){
                    if(a[i] < 10)
                        ans[cnt] += a[i] + '0';
                    else{
                        ans[cnt] = ans[cnt] + (char)(a[i] / 10 + '0') + (char)(a[i] % 10 + '0');
                    }
                }
                    
            }
        }
    }
    for (int i = 1; i <= cnt; i++){
        for (int j = 0; j < ans[i].size(); j++){
            printf("%3c", ans[i][j]);
        }
        cout << endl;
    }
        return 0;
}