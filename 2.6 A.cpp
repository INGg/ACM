#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main(){
    scanf("%d", &n);
    int a, b, c;
    if(n % 3 == 0){ // 每三个数必定有一个是3的倍数
        a = 1;
        b = 1;
        c = n - a - b;
    }
    else{
        a = 1; //隔三个一定不是3的倍数
        b = 2;
        c = n - a - b;
    }
    cout << a << " " << b << " " << c;
    return 0;
}