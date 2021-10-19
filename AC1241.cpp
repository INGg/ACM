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
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m, t;
queue<PII> q; // 代表id编号的外卖店此时的优先级

struct items{
	int ts = 0;
	int id;
	int yx = 0;
}it[100000 + 10], store[100000 + 10];

bool cmp(items a, items b){
	return a.ts < b.ts;
}

int main(){
	cin >> n >> m >> t;
	for(int i = 1; i <= m; i++){
		cin >> it[i].ts >> it[i].id;
	}
	
	sort(it + 1, it + 1 + m, cmp);
	
	int pre_time = 0;
	for(int i = 1; i <= m; i++){ // 遍历所有的订单
		// 记录上一个时刻，不同时刻，需要把里面的优先级都要进行处理，减k
		int ts = it[i].ts;
		int id = it[i].id;
		
		if(store[id].yx - (ts - store[id].ts) >= 0) //外卖更新
			store[id].yx = store[id].yx - (ts - store[id].ts) + 2; //
		else store[id].yx = 2; 
		
		store[id].ts = ts; // 存一下时间，然后遍历到他就-k个时间
		
		if(ts != pre_time){ // 不是当前时间说明要更新一下，队列里面的值，有的要出来
			
			int size = q.size();
			while(size > 0){
				auto front = q.front();
				q.pop();
				
				if(front.y - (ts - store[front.x].ts) > 3){ 
					front.y = front.y - (ts - store[front.x].ts);
					q.push(front);
					store[front.x].yx -= (ts - store[front.x].ts);
					store[front.x].id = pre_time;
				}
				else{ // 小于了3之后就不用入队了，但是要更新这几个店的值
					if(front.y - (ts - store[front.x].ts) >= 0) //外卖更新
						store[front.x].yx = front.y - (ts - store[front.x].ts); //
					else 
						store[front.x].yx = 0;
					
					store[front.x].ts = ts;
				}
				
				
				size--;
			}
			if(store[id].yx >= 5){
				q.push({id, store[id].yx});
			}
		}
		
		else{ // 是当前时间不需要对优先值进行操作，只需要更新，看看是不是要入队
			if(store[id].yx >= 5){
				q.push({id, store[id].yx});
			}
		}
		
		
		pre_time = ts;
	}
	
	cout << q.size();
	
	return 0;
}