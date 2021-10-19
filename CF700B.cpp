#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct nope{
    int a;
    int b;
} m[100000 + 10];

int A, B;
int n;

bool cmp(int a)

void work(){
    scanf("%d%d%d", &A, &B, &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &m[i].a);
    }

    for (int i = 1; i <= n; i++){
        scanf("%d", &m[i].b);
    }
    int i;
    for (i = 1; i <= n; i++){
        while(m[i].b > 0 && B > 0){
            B -= m[i].a;
            m[i].b -= m[i].a;
        }
        if(B <= 0){
            break;
        }
    }
    if(B <= 0){
        if(i == n){
            if(m[i].b <= 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
            printf("NO\n");
    }
    else if(B > 0){
        printf("YES\n");
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        work();
    }
    return 0;
}