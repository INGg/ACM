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

const int N = 2e5 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int a, b;
char s[N];

bool pd(){
    int n = strlen(s + 1);
    for (int i = 1; i <= n / 2; i++){
        if(s[i] != s[n - i + 1])
            return 0;
    }
    return 1;
}

void solve(){
    cin >> a >> b;
    scanf("%s", s + 1);

    int n = strlen(s + 1);

    if(a + b != n){
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= n; i++){
        if(s[i] == '0')
            a--;
        else if(s[i] == '1')
            b--;
    }

    if(n & 1){
        for (int i = 1; i <= n / 2; i++){
            if(s[i] == '?' && s[n - i + 1] != '?'){
                if(s[n - i + 1] == '1'){
                    b--;
                    s[i] = '1';
                }
                else if(s[n - i + 1] == '0'){
                    a--;
                    s[i] = '0';
                }
            }
            else if(s[i] != '?' && s[n - i + 1] == '?'){
                if(s[i] == '1'){
                    b--;
                    s[n - i + 1] = '1';
                }
                else if(s[i] == '0'){
                    a--;
                    s[n - i + 1] = '0';
                }
            }
        }

        for (int i = 1; i <= n / 2; i++){
            if(s[i] == '?' && s[n - i + 1] == '?'){
                if(a >= 2){
                    s[i] = s[n - i + 1] = '0';
                    a -= 2;
                }
                else if(b >= 2){
                    s[i] = s[n - i + 1] = '1';
                    b -= 2;
                }
            }
        }

        if((a == 0 && b == 0) || (a == 1 && b == 0) || (a == 0 && b == 1)){
            if(s[n / 2 + 1] == '?'){
                if(a == 1)
                    s[n / 2 + 1] = '0';
                else if(b == 1)
                    s[n / 2 + 1] = '1';
            }

            if(!pd()){
                cout << -1 << endl;
                return;
            }

            for (int i = 1; i <= n; i++){
                cout << s[i];
            }
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    else{
        for (int i = 1; i <= n / 2; i++){
            if(s[i] == '?' && s[n - i + 1] != '?'){
                if(s[n - i + 1] == '1'){
                    b--;
                    s[i] = '1';
                }
                else if(s[n - i + 1] == '0'){
                    a--;
                    s[i] = '0';
                }
            }
            else if(s[i] != '?' && s[n - i + 1] == '?'){
                if(s[i] == '1'){
                    b--;
                    s[n - i + 1] = '1';
                }
                else if(s[i] == '0'){
                    a--;
                    s[n - i + 1] = '0';
                }
            }
        }

        for (int i = 1; i <= n / 2; i++){
            if(s[i] == '?' && s[n - i + 1] == '?'){
                if(a >= 2){
                    s[i] = s[n - i + 1] = '0';
                    a -= 2;
                }
                else if(b >= 2){
                    s[i] = s[n - i + 1] = '1';
                    b -= 2;
                }
            }
        }

        if(!a && !b){
            if(!pd()){
                cout << -1 << endl;
                return;
            }

            for (int i = 1; i <= n; i++){
                cout << s[i];
            }
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}