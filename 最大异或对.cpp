#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int son[31 * N][2], idx;
// 每个数最多有31位，一个有N个数，一共需要31 * N个节点

void insert(int x){
    int p = 0;
    for (int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x){
    int p = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(son[p][!u]){ // 如果另一个方向存在，肯定走使答案变大的那个方向
            p = son[p][!u];
            res = (res << 1) + !u;
        } 
        else{
            p = son[p][u];
            res = (res << 1) + u;
        }       
    }
    return res;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        insert(a[i]);

        int t = query(a[i]);

        ans = max(ans, a[i] ^ t);
    }

    cout << ans;

    return 0;
}