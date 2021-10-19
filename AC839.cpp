#include <iostream>
#include <cstring>

using namespace std;

int n;
int m;
struct heap{
	int h[100000 + 10];
	int ph[100000 + 10];
	int hp[100000 + 10];
	int size;
	int idx; // 第几个插入的元素
	
	void h_swap(int a, int b){
		swap(ph[hp[a]], ph[hp[b]]); // 通过hp[a]找回去ph
		swap(hp[a], hp[b]);
		swap(h[a], h[b]);
	}
	
	void down(int u){
		int t = u;
		
		if(u * 2 <= size && h[u * 2] < h[t]) t = (u * 2);
		if(u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
		
		if(t != u){
			h_swap(t, u);
			down(t);
		}
	}
	
	void up(int u){
	    while(u / 2 && h[u / 2] > h[u]){
    	    h_swap(u / 2, u);
        	u /= 2;
	    }
	}
	
	void init(){
		for(int i = n / 2; i; i--){
			down(i);
		}
	}
	
	void push(int x){
		h[++size] = x;
		idx++;
		ph[idx] = size;
		hp[size] = idx;
		up(size);
	}
	
	void pop(){
		if(size){
			h_swap(1, size);
			size--;
			down(1);
		}
	}
	
	int top(){
		return h[1];
	}
	
	void pop_any(int k){
		k = ph[k];
		h_swap(k, size);
		size--;
		down(k);
		up(k);
	}
	
	void modify_any(int k, int x){
		k = ph[k];
		h[k] = x;
		down(k);
		up(k);
	}
}h;

int main(){
	cin >> n;
	
	while(n--){
		char op[5];
		scanf("%s", op);
		if(op[0] == 'I'){
			int x;
			cin >> x;
			h.push(x);
		}
		else if(op[0] == 'P'){
			cout << h.top() << endl;
		}
		else if(op[0] == 'D'){
			if(op[1] == 'M'){
				h.pop();
			}
			else{
				int k;
				cin >> k;
				
				h.pop_any(k);
			}
		}
		else if(op[0] == 'C'){
			int k, x;
			cin >> k >> x;
			h.modify_any(k, x);
		}
	}
	
	return 0;
}