#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[2000000 + 10];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= m; i++){
        cout << a[i] << " ";
    }
    return 0;
}