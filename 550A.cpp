#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define re return
#define pb push_back
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

char s[N];
int st[N];

int main(){
    scanf("%s", s);

    int l = strlen(s);

    int flag_BA = 0;
    for (int i = 1; i < l; i++){ // BA
        if(s[i] == 'A' && s[i - 1] == 'B'){
            st[i - 1] = 1; // B用过了
            st[i] = 1;
            flag_BA = 1;
            break;
        }
    }
    if(flag_BA){
        int flag = 0;
        for (int i = 1; i < l; i++){
            if(s[i] == 'B' && s[i - 1] == 'A' && !st[i] && !st[i - 1]){
                flag = 1;
                break;
            }
        }
        if(flag){
            cout << "YES";
            return 0;
        }
    }
    
        memset(st, 0, sizeof(st));
        int flag_AB = 0;
        for (int i = 1; i < l; i++){ // AB
            if(s[i] == 'B' && s[i - 1] == 'A'){
                st[i - 1] = 1; // B用过了
                st[i] = 1;
                flag_AB = 1;
                break;
            }
        }
        if(flag_AB){
            int flag = 0;
            for (int i = 1; i < l; i++){
                if(s[i] == 'A' && s[i - 1] == 'B' && !st[i] && !st[i - 1]){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout << "YES";
                return 0;
            }
        }
    
    cout << "NO";
}