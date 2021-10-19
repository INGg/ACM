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
int n;

int main(){
    cin >> T;
    while(T--){
        vector<int> ou;
        vector<int> ji;

        cin >> n;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x & 1)
                ji.pb(i);
            else
                ou.pb(i);
        }
        if(abs((int)ji.size() - (int)ou.size()) >= 2){
            cout << -1 << endl;
            continue;
        }

        int ans = 0;

        if(ji.size() > ou.size()){
            int id = 0;
            for (int i = 0; i < ji.size(); i++, id += 2){
                ans += abs((int)ji[i] - id);
            }
        }
        else if(ji.size() < ou.size()){
            int id = 0;
            for (int i = 0; i < ou.size(); i++, id += 2){
                ans += abs(ou[i] - id);
            }
        }
        else{
            int id = 0;
            for (int i = 0; i < ji.size(); i++, id += 2){
                ans += abs(ji[i] - id);
            }
            id = 0;
            int ans1 = 0;
            for (int i = 0; i < ou.size(); i++, id += 2){
                ans1 += abs(ou[i] - id);
            }

            ans = min(ans, ans1);
        }
        cout << ans << endl;
    }
}