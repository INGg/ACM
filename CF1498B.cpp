#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#define ll long long
#define re return

using namespace std;

int T;

int pow2(int n){
	int summ = 1;
	while(n--){
		summ *= 2;
	}
	re summ;
}

int main(){
    cin >> T;
    while(T--){
    	int n;
    	int w[22] = {0};
    	int W;
    	cin >> n >> W;
    	int x;
    	for(int i = 1; i <= n; i++){
			scanf("%d", &x);
			int p = log2(x);
			w[p]++;
    	}
    	
    	int h = 0;
    	while(n){
    		h++;
			int kuan = W;
			for(int i = 21; i >= 0; i--){
                int x = 1 << i;
                while(w[i] && x <= kuan){
                    w[i]--;
                    n--;
                    kuan -= x;
                }
			}
    	}
		cout << h << endl;
    }
    return 0;
}