#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool vis[100]; //bool数组存好，还省空间
int way[100];

void dfs(int num, int n){ // num是当前放在第num位上
    if(num > n){
        for (int i = 1; i <= n; i++){
            cout << way[i];
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = true;
            way[num] = i;
            dfs(num + 1, n);

            vis[i] = false;
            way[num] = 0;
        }
    }
}

int main(){
    int n;
    while(cin >> n)
    dfs(1, n);
    return 0;
}