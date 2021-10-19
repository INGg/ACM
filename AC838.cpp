#include <iostream>

using namespace std;

int n;
int m;
struct heap{
	int h[100000 + 10];
	int size;
	
	void h_swap(int a, int b){
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
		up(size);
	}
	
	void pop(){
		if(size){
			h[1] = h[size];
			size--;
			down(1);
		}
	}
	
	int top(){
		return h[1];
	}
	
	void pop_any(int k){
		heap[k] = heap[size];
		size--;
		down(k);
		up(k);
	}
	
	void modify_any(int k, int x){
		h[k] = x;
		size--;
	}
}h;

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> h.h[i];
	}
	
	h.size = n;
	
	h.init();
	
	while(m--){
		cout << h.top() << " ";
		h.pop();
	}
	
	return 0;
}