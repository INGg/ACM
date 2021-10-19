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

const int N = 30000 + 10;

int f[N]; // f[i]表示从i走出去这个点会指向哪个点
int d[N]; // 表示x在f[x]之间有多少个战舰
int sizef[N];

void init(int n){
    for(int i = 1; i <= n; i++){
     	f[i] = i;
        d[i] = 0;
        sizef[i] = 1;
    }
}

int query(int p){
    if(f[p] == p)
        return p; //说明已经走到最后一个点了
    else{
     	int v = query(f[p]); //f[p]会走到v，那么p也会走到v，那么我只需要知道f[p]走到了哪里，然后直接告诉p属于哪里就行了
     	d[p] += d[f[p]]; // 考虑递归顺序，我们先得到的是根节点后面的点到根节点的距离，然后顺着递归回溯，然后根据d数组的定义，这个点到他父亲的距离，就完成了逐个的累加
        f[p] = v;
        return v;
        // return f[p] = query(f[p]);
    }
}

void merge(int p1, int p2){
    int f1 = query(p1);
    int f2 = query(p2);
    
    if(f1 != f2){ //不是一个就加一条边
        f[f1] = f2; // f1的祖先是f2，把f1接到f2后面
        d[f1] = sizef[f2];
        sizef[f2] += sizef[f1];
	} 
}

int T;

int main(){
	init(N);
	cin >> T;
	
	while(T--){
		char s[3];
		int i, j;
		scanf("%s%d%d", s, &i, &j);
		if(s[0] == 'M'){
			merge(i ,j );
		}
		else{
			int fi = query(i);
			int fj = query(j);
			if(fi != fj){
				cout << -1 << endl;
			}
			else{
				cout << max(0, abs(d[i] - d[j]) - 1) << endl;
			}
		}
	}
	return 0;
}