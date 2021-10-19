#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#define Max(a,b) a>b?a:b
#define Min(a,b) a>b?b:a
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int dir[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
const double eps = 1e-6;
const double Pi = acos(-1.0);
const int INF=0x3f3f3f3f;
const int maxn = 5e5+10;
int zero[11], one[11];
int yu[11],huo[11],yihuo[11];
int main(){
    int n,d;
    char o;
    scanf("%d",&n);
    int a = 0, b = 1023;
    for(int i = 0; i < n; i++){
        getchar();
        scanf("%c %d",&o,&d);
        if(o == '|') a = a|d, b = b|d;
        else if(o == '^') a = a^d, b = b^d;
        else a = a&d, b = b&d;
    }
    int cnt = 1;
    while(a != 0){
        zero[cnt++] = a%2;
        a = a/2;
    }
    cnt = 1;
    while(b != 0){
        one[cnt++] = b%2;
        b = b/2;
    }

    for(int i = 1; i <= 10; i++) yu[i] = 1;
    bool op1 = false, op2 = false, op3 = false;
    for(int i = 1; i <= 10; i++){
        if(zero[i] == 0 && one[i] == 0) yu[i] = 0, op1 = true;
        else if(zero[i] == 1 && one[i] == 0) yihuo[i] = 1, op2 = true;
        else if(zero[i] == 1 && one[i] == 1) huo[i] = 1, op3 = true;
    }
    int ans = 0;
    int data[3];
    if(op1){
        ans++;
        data[0] = 0;
        for(int i = 1; i <= 10; i++){
            data[0] += yu[i]*pow(2,i-1);
        }
    }
    if(op2){
        ans++;
        data[1] = 0;
        for(int i = 1; i <= 10; i++){
            data[1] += yihuo[i] * pow(2,i-1);
        }
    }
    if(op3){
        ans++;
        data[2] = 0;
        for(int i = 1; i <= 10; i++){
            data[2] += huo[i] * pow(2,i-1);
        }
    }
    printf("%d\n",ans);
    if(op1) printf("& %d\n",data[0]);
    if(op2) printf("^ %d\n",data[1]);
    if(op3) printf("| %d\n",data[2]);
}
