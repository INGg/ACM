#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int zero[15], one[15];
int yu[10], huo[10], yihuo[10];

int main(){
    int n;
    int a = 0;
    int b = 1023;
    cin >> n;
    string op;
    int d;
    int ad = 0; // 标志
    int h = 0;
    int yh = 0;
    for (int i = 1; i <= n; i++){
        cin >> op >> d;
        if(op == "&"){
            a &= d;
            b &= d;
        }

        else if(op == "|"){
            a |= d;
            b |= d;
        }

        else if(op == "^"){
            a ^= d;
            b ^= d;
        }
    }

    

    int cnt = 0;
    while(a != 0){
        zero[++cnt] = (a % 2);
        a /= 2;
    }
    cnt = 0;
    while(b != 0){
        one[++cnt] = (b % 2);
        b /= 2;
    }

    for (int i = 1; i <= 10; i++)
        yu[i] = 1;

    //对对应的每一位操作来看是不是应该进行一些操作

     for (int i = 1; i <= 10; i++)
     {
        if (zero[i] == 1 && one[i] == 1)
        {
            huo[i] = 1;
            h = 1;
        }

        else if (zero[i] == 0 && one[i] == 0)
        {
            yu[i] = 0;
            ad = 1;
        }

        else if (zero[i] == 1 && one[i] == 0)
        {
            yihuo[i] = 1;
            yh = 1;
        }
    }

    int ans = 0;
    int ans_num[5] = {0};
    if(ad){
        ans++;
        for (int i = 1; i <= 10; i++){
            ans_num[1] += (yu[i] * pow(2, i - 1));
        }
    }

    if(yh){
        ans++;
        for (int i = 1; i <= 10; i++){
            ans_num[2] += (yihuo[i] * pow(2, i - 1));
        }
    }

    if(h){
        ans++;
        for (int i = 1; i <= 10; i++){
            ans_num[3] += (huo[i] * pow(2, i - 1));
        }
    }

    

    cout << ans << endl;
    if(ad)
        printf("& %d\n", ans_num[1]);
    if(yh)
        printf("^ %d\n", ans_num[2]);
    if(h)
        printf("| %d\n", ans_num[3]);
    return 0;
}