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
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
ll n;

void solve(){
    cin >> n;
    if(n <= 100){
        cout << 0 << endl;
        return;
    }
    string s;
    stringstream ss;

    ss << n;
    ss >> s;

    int res1 = 0;
    int flag = 0;
    for (int i = s.size() - 1; i >= 0; i--){
        if(s[i] == '0'){
            for (int j = i - 1; j >= 0; j--){
                if(s[j] == '0' || s[j] == '5'){
                    flag = 1;
                    break;
                }
                res1++;
            }
            if(flag){
                break;
            }
        }
        res1++;
    }

    flag = 0;
    int res2 = 0;
    for (int i = s.size() - 1; i >= 0; i--){
        if(s[i] == '5'){
            for (int j = i - 1; j >= 0; j--){
                if(s[j] == '2' || s[j] == '7'){
                    flag = 1;
                    break;
                }
                res2++;
            }
            if(flag){
                break;
            }
        }
        res2++;
    }

    cout << min(res1, res2) << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}