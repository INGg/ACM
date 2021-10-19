#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[10000 + 10];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        int maxx = 0;
        int minn = 9999999;
        for (int j = i; j <= n; j++){ // 一定要向后枚举，也就是说，j确定的是右端点，只有确定了右端点，才能保证每次加入一个新的元素，最大值能够合法改变
            maxx = max(maxx, a[j]);
            minn = min(minn, a[j]);
            if(j -i == maxx - minn)
                ans++;
        }
    }
    cout << ans;
    return 0;
}