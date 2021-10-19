// 用冒泡法对数组中10个整数排序（由小到大）。

#include <stdio.h>

const int N = 0xAF;

int main(){
    int a[10];

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10 - i; j++){
            if (a[j] > a[j + 1]){
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    return 0;
}
