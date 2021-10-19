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

const int N = 200 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;

// 结构体版
struct ufss{
	map<PII, PII> f;
	
	void init(){
        for(int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                f[{i, j}] = {i, j};
            }
        }
	}
	
	PII query(PII p){
		if(f[p] == p) return p;
			else{
				PII v = query(f[p]);
				f[p] = v;
				return v;
			}
	}

	void merge(PII p1,PII p2){
		PII f1 = query(p1);
		PII f2 = query(p2);
		if(f1 != f2){
			f[f1] = f2;
		}
	}
	
	bool pd(PII p1, PII p2){
		if(query(p1) == query(p2)) return true;
			else return false;
	}
    
    // int count(n){
    //     int ans = 0;
    //     for(int i = 1; i <= n; i++) if(f[i] == i) ans++;
        
	// }
}ufs;

int main(){
    cin >> n >> m;
    ufs.init();

    for (int cnt = 1; cnt <= m; cnt++){
        int x, y;
        char op[2];

        cin >> x >> y;
        scanf("%s", op);

        if(op[0] == 'D'){
            if(ufs.pd({x,y}, {x + 1, y})){
                cout << cnt;
                return 0;
            }
            else{
                ufs.merge({x, y}, {x + 1, y});
            }
        }
        else{
            if(ufs.pd({x,y}, {x, y + 1})){
                cout << cnt;
                return 0;
            }
            else{
                ufs.merge({x, y}, {x, y + 1});
            }
        }  
    }

    cout << "draw";
}