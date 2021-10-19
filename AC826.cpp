#include <iostream>

using namespace std;

const int N = 100010;

/* 
head 表示头节点的下标
e[i] 表示节点i的值
ne[i] 表示节点i的next指针是多少
idx 当前最大已经用到了哪个点，目的是为了方便后续添加新的链表
*/

int head;
int e[N];
int ne[N];
int idx;

void init(){
	head = -1; // 表示空集
	idx = 1; // 当前点可以从0号开始分配
}

void add_to_head(int x){ // 讲x插入头结点
	// 把新节点的指针，指向head指向的点
	ne[idx] = head;
	
	// 把x的值赋给这个链表
	e[idx] = x;
	
	// 讲head的指针删除，指向x的地址
	head = idx;
	
	// 这个点已经用过了，需要转移
	idx++;
}

void add(int k, int x){ // 一般插入，讲x插入到k节点的后面
	// 建立新的指针，指向k节点原本所指的位置
	ne[idx] = ne[k];
	
	// 插入k节点的后面，那么k的后面的就是现在这个要插入的节点
	ne[k] = idx;
	
	// 这个节点的值是x
	e[idx] = x;
	
	// 这个点已经用过了需要转移
	idx++;
}

void delete_node(int k){ // 将下标为k的后面的点删掉
	// 直接跳过k后面的点指向下一个点就可以了
	ne[k] = ne[ne[k]];
	
}

int main(){
    int m;
	cin >> m;
	
	init();
	
	while(m--){
	    char op;
	    cin >> op;
	    if(op == 'H'){
	        int x;
	        cin >> x;
	        add_to_head(x);
	    }
	    else if(op == 'D'){
	        int k;
	        cin >> k;
	        if(!k) head = ne[head];
	        else delete_node(k);
	    }
	    else{
	        int k, x;
	        cin >> k >> x;
	        add(k, x);
	    }
	}
	
	for(int i = head; i != -1; i = ne[i]){
	    cout << e[i] << " ";
	}
	return 0;
}