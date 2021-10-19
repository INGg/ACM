#include <iostream>

using namespace std;

int q[100000 + 10];
int tmp[100000 + 10];

void merge_sort(int q[], int l, int r){
    if(l >= r) 
        return;
    
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    
    int k = 0;
    int i = l;
    int j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]){
            tmp[k++] = q[i++];
        }
        else{
            tmp[k++] = q[j++];
        }
    }
    
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    
    for(int i = 0, j = l; j <= r; i++, j++){
        q[j] = tmp[i];
    }
}

int main(){
    int n;
    for(int i = 1; i <= n; i++){
        scanf("%d",q + i);
    }
    
    merge_sort(q, 1, n);
    
    for(int i = 1; i <= n; i++){
        printf("%d ",q[i]);
    }
    return 0;
}