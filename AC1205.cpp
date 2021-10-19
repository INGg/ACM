#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long

using namespace std;
int a[10000] = {0};

int main(){
    for (int p = 2; p <= 15; p++){
        for (int q = 2; q <= 15; q++){
            memset(a, 0, sizeof(a));
            // int flag = 0;
            for (int i = 0; i <= 500; i++){
                for (int j = 0; j <= 500; j++){
                    int x = p * i + q * j;
                    if(x <= 1000)
                        a[x] = 1;
                }
            }
            printf("%d %d: ", p, q);
            for (int i = 1; i <= 1000; i++){
                if(a[i] != 1)
                    printf("%d ", i);
            }
            printf("\n");
        }
    }
}