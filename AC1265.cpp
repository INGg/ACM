#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int tr[32000 + 10];
int num[32000 + 10];

int lb(int x){
    return x & -x;
}

int query(int p){
    int ans = 0;
    for (; p; p -= lb(p)){
        ans += tr[p];
    }
    return ans;
}

void modify(int p, int v){
    for (; p <= 32005; p += lb(p)){
        tr[p] += v;
    }
}

int main(){
    int n;
    cin >> n;
    //统计x坐标前面有多少个星星
    for (int i = 1; i <= n; i++){
        int x;
        int y;
        cin >> x >> y;
        x++;
        num[query(x)]++;
        modify(x, 1);
    }
    for (int i = 0; i < n; i++){
        cout << num[i] << endl;
    }
    return 0;
}