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

const int N = 50000 + 100;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int m[128];
char x[N];
string s[N];

bool cmp(string a, string b){
    if(a == b){
        return 1;
    }

    int la = a.size();
    int lb = b.size();

    int l = min(la, lb);

    for (int i = 0; i < l; i++){
        if(a[i] == b[i]){
            continue;
        }
        else if(m[a[i]] < m[b[i]]){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(la < lb)
        return 1;
    else
        return 0;
}

int main(){
    scanf("%s",x+1);
    int len = strlen(x+1);
    for (int i=1;i<=len;i++){
        m[x[i]]=i;
    }
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> s[i];
    }
    sort(s + 1, s + 1 + n, cmp);
    for (int i=1;i<=n;i++){
        cout << s[i] << Endl;
    }
    return 0;
}