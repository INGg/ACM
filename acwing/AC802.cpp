// Problem: 数组元素的目标和
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/802/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>

using namespace std;

int n, m, x;

int a[100000 + 10];
int b[100000 + 10];

int main(){
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    
    int i = 0;
    int j = m - 1;
    while(i < n && j >= 0){
        int summ = a[i] + b[j];
        if(summ == x){
            cout << i << " " << j;
            return 0;
        }
        
        if(summ > x){
            j --;
        }
        else{
            i++;
        }
    }
    
    return 0;
}