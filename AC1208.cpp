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

//翻动相邻的两个，只要相邻就行

char a[120];
char golb[120];

void turn(int x){
    if(a[x] == 'o')
        a[x] = '*';
    else
        a[x] = 'o';
    if(a[x + 1] == 'o')
        a[x + 1] = '*';
    else
        a[x + 1] = 'o';
}

int main(){
    fgets(a, sizeof(a), stdin);
    // getchar();
    fgets(golb, sizeof(golb), stdin);
    // getchar();

    int l = strlen(a);
    int ans = 0;
    for (int i = 0; i < l; i++){
        if(a[i] != golb[i]){
            turn(i);
            ans++;
        }
    }
    cout << ans << endl;
    re 0;
}

// *o**o***o***
// *o***o**o***