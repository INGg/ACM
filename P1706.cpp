#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[20];
    for (int i = 1; i <= n; i++)
        a[i] = i;
    do{
        for (int i = 1; i <= n; i++){
            printf("%5d", a[i]);
        }
        printf("\n");
    } while (next_permutation(a + 1, a + 1 + n));
    return 0;
}