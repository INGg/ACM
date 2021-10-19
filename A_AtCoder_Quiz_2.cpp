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

int x;

int main(){
    cin >> x;
    if(x >= 90){
        cout << "expert";
        return 0;
    }
    else if(x < 40){
        cout << 40 - x;
    }
    else if(x < 70){
        cout << 70 - x;
    }
    else{
        cout << 90 - x;
    }
    re 0;
}