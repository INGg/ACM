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
int b[N];

void init(){
    for (int i = 1; i <= n; i++)
        b[i] = i;
}

int main(){
    // init();
    cin >> T;
    while(T--){
        cin >> n;

        init();

        if(n == 2){
            cout << "2 1 " << endl;
            continue;
        }
        else if(n == 3){
            cout << "3 1 2" << endl;
            continue;
        }

        if(n & 1){
            for (int i = 1; i <= n; i += 2){
                swap(b[i], b[i + 1]);
            }

            for (int i = 1; i <= n - 3;i ++){
                cout << b[i] << ' ';
            }

            printf("%d %d %d\n", n, n - 2, n - 1);
        }
        else{
            for (int i = 1; i <= n; i += 2){
                swap(b[i], b[i + 1]);
            }
            for (int i = 1; i <= n; i++)
                cout << b[i] << " ";
            cout << endl;
        }
    }
}