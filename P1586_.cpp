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

const int N = 32768 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
int f[N][50];


int main(){

    f[0][0] = 1;
    for (int i = 1; i * i <= 32768; i++){
        for (int j = i * i; j <= 32768; j++){
            for (int k = 1; k <= 4; k++){
                f[j][k] += f[j - i * i][k - 1];
            }
        }
    }

        cin >> T;
    while(T--){
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= 4; i++)
            ans += f[n][i];
        cout << ans << endl;
    }
}