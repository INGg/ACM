#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int cnt[N];
PII logs[N];
bool is[N];
int k, d, n;

int main(){
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i++){
        cin >> logs[i].first >> logs[i].second;
    }
    
    sort(logs + 1, logs + 1 + n); //  第一对时间进行排序，然后以名字为第二关键字 
    
    for(int i = 1, j = 1; j <= n; j++){ //  枚举每一条帖子
    	int id = logs[j].second; //  每次都会新加进来一个帖子
    	cnt[id]++;
    	while(logs[j].first - logs[i].first >= d){ // 目前j帖子与i帖子的时间跨度就要用哪个区间，就说明超时间d了，得减去
    		cnt[logs[i].second]--;
    		i++;
    	}
    	
    	if(cnt[id] >= k) is[id] = 1;
    	
    }
    
    for(int i = 0; i <= N - 1; i++){
		if(is[i]) cout << i << endl;
    }
    return 0;
}