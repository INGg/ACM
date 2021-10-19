#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define ll long long
#define re return

using namespace std;

typedef pair<int, int> PII;

const int N = 50000 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int f[N]; //f[i]表示从i走出去这个点会指向哪个点
int sizef[N];

void init(int n){
    for(int i = 1; i <= n; i++){
     	f[i] = i;
        sizef[i] = 1;
    }
}

int query(int p){
    if(f[p] == p)
        return p; //说明已经走到最后一个点了
    else{
     	int v = query(f[p]); //f[p]会走到v，那么p也会走到v，那么我只需要知道f[p]走到了哪里，然后直接告诉p属于哪里就行了
        f[p] = v;
        return v;
        // return f[p] = query(f[p]);
    }
}

void merge(int p1, int p2){
    int f1 = query(p1);
    int f2 = query(p2);
    
    if(f1 != f2){ //不是一个就加一条边
        f[f1] = f2; // f1的祖先是f2
        sizef[f2] += sizef[f1]; // 根据sizef数组的定义，这样能保证正确性
	} 
}

int n, k;
int d, x, y;

int main(){
	cin >> n >> k;
	init(n);
	int ans = 0;
	while(k--){
		cin >> d >> x >> y;
		if(x > n || y > n) ans++;
		
		if(d == 1){
			if(query(x) != query(y)) ans++;
		}
		else{
			
		}
	}
}