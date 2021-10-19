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

const int N = 30 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
char s[N];

int main(){
    cin >> T;
    while(T--){
        scanf("%s", s + 1);
        int l = strlen(s + 1);

        if(s[l - 6 + 1] == 'h'){
            if(s[l - 7 + 1] == 'c'){
                for (int i = 1; i < l - 7 + 1; i++){
                    cout << s[i];
                }
                cout << "tte\n";
            }
            else if (s[l - 7 + 1] == 's'){
                for (int i = 1; i < l - 7 + 1; i++){
                    cout << s[i];
                }
                cout << "shite\n";
            }
        }
        else if(s[l - 6 + 1] == 'r'){
            for (int i = 1; i <= l - 7 + 1; i++){
                cout << s[i];
            }
            cout << "tte\n";
        }
        else if(s[l - 6 + 1] == 'm' || s[l - 6 + 1] == 'b' || s[l - 6 + 1] == 'n'){
            for (int i = 1; i <= l - 7 + 1; i++){
                cout << s[i];
            }
            cout << "nde\n";
        }
        else if(s[l - 6 + 1] == 'k'){
            if(s[l - 7 + 1] == 'i' && l == 7){
                cout << "itte" << endl;
                continue;
            }
            for (int i = 1; i <= l - 7 + 1; i++){
                cout << s[i];
            }
            cout << "ite\n";
        }
        else if(s[l - 6 + 1] == 'g'){
            for (int i = 1; i <= l - 7 + 1; i++){
                cout << s[i];
            }
            cout << "ide\n";
        }
    }
}