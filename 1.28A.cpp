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

int n, m;
int num[20];
int xu[20];
int zhi_wen[20];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> xu[i];
    }

    for (int i = 1; i <= m; i++){
        cin >> zhi_wen[i];
        num[zhi_wen[i]]++;
    }

    for (int i = 1; i <= n; i++){
        if(num[xu[i]])
            cout << xu[i] << " ";
    }
    return 0;
}