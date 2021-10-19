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
#define Endl "\n"
#define endl "\n"

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int m[50];

struct nope{
	int x;
	int id;
} summ[50];

int x[] = {1, 5, 10, 20, 50, 100};

bool cmp(nope a, nope b){
	if(a.x == b.x){
		return a.id > b.id;
	}
	return a.x > b.x;
}

int main(){
	for(int i = 1; i <= 6; i++){
		cin >> summ[i].x;
		summ[i].id = x[i - 1];
		summ[i].x = summ[i].x * x[i - 1];
		// cout << summ[i].x  << Endl;
	}
	
	sort(summ + 1, summ + 1 + 6 ,cmp);
	
	cout << summ[1].id;
	
}