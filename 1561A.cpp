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

const int N = 1e3 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
int a[N];
int b[N];

bool pd(){
    for (int i = 1; i <= n; i++){
        if(b[i] != a[i])
            return 0;
    }
    return 1;
}

void f(int x){
    if(x % 2 != 0){
        for (int i = 1; i <= n - 2; i += 2){
            if(a[i] > a[i + 1]){
                swap(a[i], a[i + 1]);
            }
        }
    }
    else{
        for (int i = 2; i <= n - 1; i += 2){
            if(a[i] > a[i + 1]){
                swap(a[i], a[i + 1]);
            }
        }
    }
}

void debug(){
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << Endl;
}

int main(){
    for (int i = 1; i <= 1000; i++){
        b[i] = i;
    }

    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int i = 0;
        while(!pd()){
            f(++i);
            // debug();
        }
        cout << i << endl;
    }
}