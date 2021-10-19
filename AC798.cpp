#include <iostream>
#include <cstdio>

using namespace std;

int n, q, k;

int a[100000 + 10];

int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    while(q--){
        cin >> k;
        int l = 1;
        int r = n;
        while(l < r){ //找起始位置,要是起始位置则要满足在x位置处，右边的所有值要大于等于k的值
            int mid = (l + r) / 2;
            if(a[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }
        if(a[r] != k)
            cout << "-1 -1" << endl;
        else{
            cout << l - 1 << " ";
            int l = 1;
            int r = n;
            while(l < r){
                int mid = (l + r + 1) / 2;
                if(a[mid] <= k)
                    l = mid;
                else
                    r = mid - 1;
            }
                cout << r - 1 << endl;
            }
        }
    return 0;
}