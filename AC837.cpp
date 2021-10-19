#include <iostream>

using namespace std;

const int N = 100000 + 10;

int f[N]; //f[i]表示从i走出去这个点会指向哪个点
int sizef[N];

void init(int n){
    for(int i = 1; i <= n; i++){
     	f[i] = i;
        sizef[i] = 1;
    }
}

int query(int p){
    if(f[p] == p)
        return p; //说明已经走到最后一个点了
    else{
     	int v = query(f[p]); //f[p]会走到v，那么p也会走到v，那么我只需要知道f[p]走到了哪里，然后直接告诉p属于哪里就行了
        f[p] = v;
        return v;
        // return f[p] = query(f[p]);
    }
}

void merge(int p1, int p2){
    int f1 = query(p1);
    int f2 = query(p2);
    
    if(f1 != f2){ //不是一个就加一条边
        f[f1] = f2; // f1的祖先是f2
        sizef[f2] += sizef[f1]; // 根据sizef数组的定义，这样能保证正确性
	} 
}

int n, m;
char s[3];
int a, b;

int main(){
    cin >> n >> m;
    init(n);
    while(m--){
		scanf("%s", s);
		if(s[0] == 'C'){
			cin >> a >> b;
			merge(a, b);
		}
		else if(s[1] == '1'){
			cin >> a >> b;
			if(query(a) == query(b)){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
		else{
			cin >> a;
			cout << sizef[query(a)] << endl;
		}
    }
    return 0;
}