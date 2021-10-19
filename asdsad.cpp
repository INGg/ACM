#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int t, n;
int a[55], b[55];
pair <int, int> ans[55];

void debug(){
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

inline void work(int l, int r){
	int tmp = a[r];
	for (int i = l + 1; i <= r; i++) a[i] = a[i - 1];
	a[l] = tmp;
}

int main(){
	
	cin >> t;
	while (t--){
		int k = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++){
			while (a[i] != b[i]){
				int flag = false;
			//	cout << "%";
				for (int j  = i + 1; j <= n; j ++){
					if (a[j] < a[i] && !flag){
						work(i, j);
						
						ans[++k].first = i, ans[k].second = j;
						//cout << i << " " << j << " " << endl;
						flag = true;
                        debug();
                    } 
				}
			}
		}
		cout << k << endl;
		for (int i = 1; i <= k; i++) 
			cout << ans[i].first << " " << ans[i].second <<" " << ans[i].second - ans[i].first<< endl;
	}
	return 0;
}
