#include <iostream>

using namespace std;

int N;
int a[100 + 10];
int num[100000 + 10];

int main(){
    cin >> N; // line
    int n = 0;
    int m = 0;
    int maxx = 0;
    int minn = 100000 + 10;
    int cnt = 1;
    int x;
    while(cin >> x){
        // cin >> a[i];
        num[x]++;
        maxx = max(maxx, x);
        minn = min(minn, x);
        if (num[x] == 2)
            n = x;
        // cnt++;
    }
    for (int i = minn; i <= maxx; i++){
        if(num[i] == 0){
            m = i;
            break;
        }
            
    }
    cout << m << " " << n;
    return 0;
}