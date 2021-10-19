#include <iostream>

using namespace std;

const int N = 100000 + 10;

int n;
int e[N], l[N], r[N], idx;

void init(){
	r[0] = 1;
	l[1] = 0;
	idx = 2;
}

// k的右边插入add(k)，在k的左边插入，就是add(l[k]);
void add(int k, int x){ // 中间插一个节点，将节点的左右两端插入到k和k+1，改变k的右边和k+1的左边
	e[idx] = x;
	// 四条边
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx; // 注意下面两个的顺序
	r[k] = idx;
}

// 删除第k个点
void remove(int k){
	
	r[l[k]] = r[k];
	l[r[k]] = l[k];
	
}

int main(){
	
}