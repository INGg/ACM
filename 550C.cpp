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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

string s;
int base[10000];

void init(){
    for (int i = 0; i <= 1000 / 8 + 1;i++){
        base[i] = i * 8;
    }
}

string tostr(int a){
    stringstream ss;
    ss << a;
    string s;
    ss >> s;
    return s;
}

int main(){
    init();
    cin >> s;
    int flag = 0;
    int l = s.size();
    string b;
    for (int k = 0; k < 1000 / 8 + 1; k++){
        b = "";
        b = tostr(base[k]);
        int lb = b.size();
        int i = 0;
        int j = 0;
        for (i = 0; i < l; i++){
            if(b[j] == s[i]){
                j++;
            }
        }
        if(j == lb){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout << "YES" << endl;
        cout << b;
    }
    else{
        cout << "NO";
    }
}