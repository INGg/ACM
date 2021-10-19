#include <iostream>
#include <algorithm>

using namespace std;

int a[100];
int n;
int l = 0; //左边向右走
int r = 0; // 右边向左走

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++){
        if(abs(a[i]) < abs(a[1]) && a[i] > 0)
            l++;
        if(abs(a[i]) > abs(a[1]) && a[i] < 0)
            r++;
    }
    int ans = 0;
    if(a[1] > 0){
        if(r > 0)
            ans = r + l + 1;
        else
            ans = 1;
    }
    else{
        if(l > 0)
            ans = r + l + 1;
        else
            ans = 1;
    }
    cout << ans;
    return 0;
}