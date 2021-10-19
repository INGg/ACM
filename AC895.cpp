#include <iostream>

using namespace std;

int n;
int a[1000 + 10];
int f[1000 + 10]; // f[i]表示以i结尾的最长的子序列的长度

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        f[i] = 1; //当a[i]自成一类的
        for (int j = 1; j < i; j++){
            if(a[j] < a[i]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}