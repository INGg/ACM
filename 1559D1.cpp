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
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define re return
#define pb push_back
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m1, m2;

// 结构体版
struct ufss{
	int f[N];
	
	void init(){
		for(int i = 1; i <= n; i++){
			f[i] = i;
		}
	}
	
	int query(int p){
		if(f[p] == p) return p;
			else{
				int v = query(f[p]);
				f[p] = v;
				return v;
			}
	}

	void merge(int p1,int p2){
		int f1 = query(p1);
		int f2 = query(p2);
		if(f1 != f2){
			f[f1] = f2;
		}
	}
	
	bool pd(int p1, int p2){
		if(query(p1) == query(p2)) return true;
			else return false;
	}
    
    int count(int n){
        int ans = 0;
        for(int i = 1; i <= n; i++) if(f[i] == i)
                ans++;
        return ans;
    }
}ufs1, ufs2;

vector<PII> ans;

int main(){
    cin >> n >> m1 >> m2;

    ufs1.init();
    ufs2.init();

    for (int i = 1; i <= m1; i++){
        int a, b;
        cin >> a >> b;
        ufs1.merge(a, b);
    }

    for (int i = 1; i <= m2; i++){
        int a, b;
        cin >> a >> b;
        ufs2.merge(a, b);
    }

    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if(!ufs1.pd(i, j) && !ufs2.pd(i, j)){
                ans.pb({i, j});
                ufs1.merge(i, j);
                ufs2.merge(i, j);
            }
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.x << " " << i.y << endl;
    }
}