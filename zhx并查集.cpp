#include <iostream>

using namespace std;

int f[N]; //f[i]表示从i走出去这个点会指向哪个点

int query(int p){
    if(f[p] == p)
        return p; //说明已经走到最后一个点了
    else{
     	int v = quert(f[p]); //f[p]会走到v，那么p也会走到v，那么我只需要知道f[p]走到了哪里，然后直接告诉p属于哪里就行了
        f[p] = v;
        return v;
        // return f[p] = query(f[p]);
    }
}

void merge(int p1, int p2){
    int f1 = query(p1);
    int f2 = query(p2);
    
    if(f1 != f2) //不是一个就加一条边
        if(rand()%2) //出题人会按一种方式合并的数据来卡，这样我自己都不知道我按什么方法合并的
            f[f1] = f2;
    	else 
            f[f2] = f1;
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){ //init一开始自己属于自己
        f[i] = i;
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++){
        int z, x, y;
        cin >> z >> x >> y;
        if(z == 1)
    }
}