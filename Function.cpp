#include <iostream>
#include <vector>
using namespace std;
int t, a, b, c, d, n, mixdig;
long long f(int x, int gx){
	return 1ll * ( (a * gx + b) * x * x + (c * gx * gx + d * gx));
}
int main(){
	cin >> t;
	while(t--){
		vector<int> aa[60];
		// cin >> a >> b >> c >> d >> n;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
        mixdig = 0;
		for(int i = 1, j, sum ; i <= n; i++) {
			sum = 0, j = i;
			while(j){
				sum += j % 10;
				j /= 10;  
			}
			if(!aa[sum].empty()) continue;
			aa[sum].push_back(i); 
			mixdig = max(mixdig, sum);
		}
		long long minn = 9223372036854775800;
		for(int i = 1;i <= mixdig; i++){
			minn = min(minn, f(aa[i][0], i));
			aa[i].clear();
		}

        printf("%d\n", minn);
    }
	return 0;
}
