#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <vector>
#include <sstream>
#define ll long long
#define re return

using namespace std;

int a[10] = {1, 1, 1, 0, 0, 1, 0, 0, 1, 0};
int T;
int zhuan[10] = {0, 1, 2, -1, -1, 5, -1, -1, 8, -1};

int main(){
    cin >> T;
    int h, m;
    string hh, mm;
    string s;
    while(T--){
        cin >> h >> m;
        cin >> s;
        int i;
        int flag = 0;
        for (i = 0; i < s.size(); i++){
            if(s[i] != ':'){
                hh += s[i];
                continue;
            }
            if(s[i] == ':')
                break;
            if(!a[s[i] - '0']){
                flag = 1;
                break;
            }
        }
        for (i = i + 1; i < s.size(); i++){
            mm += s[i];
            if(!a[s[i] - '0']){
                flag = 1;
                break;
            }
        }
        // cout << hh << endl;
        // cout << mm << endl;
        int hx;
        int mx; 
        stringstream s1;
        s1 << hh;
        s1 >> hx;
        stringstream s2;
        s2 << mm;
        s2 >> mx;
        // cout << hx << endl;
        // cout << mx << endl;
        if(hx >= m || mx >= h){
            flag = 1;
        }
        if(flag){
            printf("00:00");
        }
        else{
            for (int i = hh.size() - 1; i >= 0; i--){
                printf("%d", zhuan[hh[i] - '0']);
            }
            printf(":");
            for (int i = mm.size() - 1; i >= 0; i--){
                printf("%d", zhuan[mm[i] - '0']);
            }
        }
        cout << endl;
    }
    re 0;
}