#include <iostream>

using namespace std;

int n;
int way[15];
int vis[15];

void dfs(int num){ // 现在枚举到第num位
    if (num == n + 1){
        for(int i = 1; i <= n; i++){
            cout << way[i] << " ";
        }
        cout << endl;
        return;
    }
    
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            way[num] = i;
            vis[i] = 1;
            dfs(num + 1);
            vis[i] = 0;
            way[num] = 0;
        }
    }
}

int main(){
    cin >> n;
    dfs(1);
    return 0;
}