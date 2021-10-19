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

const int N = 100 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
int a[N];

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        int flag = 1;
        int maxx = -200 ;

        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] < 0)
                flag = 0;
            maxx = max(maxx, a[i]);
        }

        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        else{
            cout << "YES" << endl;
        }
        cout << maxx + 1 << endl;
        for (int i = 0; i <= maxx; i++){
            cout << i << " ";
        }
        cout << Endl;
    }
}