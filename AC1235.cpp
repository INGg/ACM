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

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
double S;
int a[500000 + 10];

int main(){
	cin >> n >> S;
	ll summ = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d",a + i);
		// summ += a[i];
	}
	
	double avg = S * 1.0 / n;
	
	// 让平方和最小，就是让付的钱尽可能的贴近平均值
	// 如果有的钱大约平均值就让他付平均值
	
	sort(a + 1, a + 1 + n);
	double s = 0;
	for(int i = 1; i <= n; i++){
		double x =  S / (n - i + 1);
		if(a[i] < x){
			x = a[i];
		}
		s += (x - avg) * (x - avg);
		S -= x;
	}
	
	printf("%.4lf",sqrt(s / n));
	
	re 0;
}