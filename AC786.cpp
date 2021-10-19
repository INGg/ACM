#include <iostream>

using namespace std;

int n, k;
int a[100000 + 10];

void quick_sort(int q[], int l, int r){
    if(l >= r)
        return;
    int i = l - 1;
    int j = r + 1;
    int x = q[(l + r) / 2];
    while(i < j){
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if(i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    quick_sort(a, 1, n);
    cout << a[k] << endl;
    return 0;
}