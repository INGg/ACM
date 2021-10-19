#include <iostream>

using namespace std;

int n;
int stk[100000 + 10];
int tt;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		while(tt && stk[tt] >= x) tt--;
		if(tt){
			cout << stk[tt] << " ";
		}
		else{
			cout << -1 << " ";
		}
		
		stk[++tt] = x;
	}
	return 0;
}