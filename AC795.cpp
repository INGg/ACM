#include <iostream>

using namespace std;

int a[100000 + 10];
int s[100000 + 10];

int main(){
    int n;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
        s[i] = s[i - 1] + a[i];
    }

    int l, r;
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &l, &r);
        printf("%d\n",s[r] - s[l - 1]);
    }

    return 0;
}