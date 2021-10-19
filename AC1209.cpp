#include <iostream>
#include <cstdio>

using namespace std;

int n;
int way[15];
bool vis[10];

int number(int start, int end){
    int t = 0;
    for (int i = start; i <= end; i++){
        t = t * 10 + way[i];
    }
    return t;
}

int ans = 0;

void dfs(int num){
    if(num > 9){
        for (int i = 1; i < 8; i++){
            for (int j = i + 1; j < 9; j++){
                int a = number(1, i);
                int b = number(i + 1, j);
                int c = number(j + 1, 9);
                if(n * c == a * c + b)
                    ans++;
            }
        }
        return;
    }

    for (int i = 1; i <= 9; i++){
        if(!vis[i]){
            vis[i] = true;
            way[num] = i;
            dfs(num + 1);
            vis[i] = false;
            // way[num] = 0;
        }
    }
}

int main(){
    cin >> n;
    dfs(1); //当前第几个数字
    cout << ans << endl;
    return 0;
}