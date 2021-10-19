#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;

int main(){
	cin >> n;
	
	int x;
	int s = 1;
	ll lp = 1, ln = 0;
	ll rp = 0, rn = 0;
	
	for(int i = 1; i <= n; i++){
		cin >> x;
		if(x < 0) s *= -1;
		if(s > 0) rn += ln, rp += lp, lp++;
		else rp += ln, rn += lp, ln++; 
	}
	
	cout << rn << " " << rp << endl;
	return 0;
}