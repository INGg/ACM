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

const int N = 1000 + 10;
const int mod = 10000;

int n, k;
int f[N][N];
int summ;

int main(){
    cin >> n >> k;
    f[1][0] = 1;
    for (int i = 2; i <= n; i++){
        summ = 0;
        for (int j = 0; j <= k; j++){
            summ += f[i - 1][j];
            f[i][j] = summ % mod;
            if(j - i + 1 >= 0)
                summ = (summ - f[i - 1][j - i + 1] + mod) % mod;
        }
    }

    cout << f[n][k];
}