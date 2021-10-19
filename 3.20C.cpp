#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#define ll long long
#define re return

using namespace std;

map<string, int> m;

int N, M;
int way[110];

int id;
string s;
int cnt = 0;

void dfs(int num){
    if(num == N + 1){
        s = "";
        for (int i = 1; i <= N; i++){
            if(way[i])
                s += 'y';
            else
                s += 'n';
        }
        m[s] = (++id);
        return;
    }

    way[num] = 1;
    dfs(num + 1);
    way[num] = 0;
    dfs(num + 1);
    way[num] = 0;
}

string ss;

int main(){
    cin >> N >> M;
    // dfs(1);
    for (int i = 1; i <= M; i++){

        cin >> ss;
        int l = ss.size();
        int x = 0;
        for (int i = 0; i < l; i++){
            if(ss[i] == 'y')
                x = (x << 1);
            else
                x = (x << 1) + 1;
        }
        cout << x  + 1<< endl;
    }
    re 0;
}