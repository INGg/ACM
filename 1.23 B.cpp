#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define ll long long

using namespace std;

ll n, k;
ll a[500 + 10];
queue<ll> q;

// struct queue{
//     ll q[1000 + 100];
//     int top = 1;
//     int end = 1;

//     void pop(){
//         top++;
//     }

//     void push(int n){
//         q[++end] = n;
//     }

//     int front(){
//         return q[top];
//     }
// }q;


//模拟
//还有好办法吗？好像桶来看看能行吗
//模拟队列，

int main(){
    cin >> n >> k;
    ll maxx = -1;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        q.push(a[i]);
        maxx = max(maxx, a[i]); //找最大的
    }

    ll ans = 0;
    ll now_power = q.front(); //当前第一个来打球
    q.pop();//弹出第一个
    while(ans != k){
        ll next_power = q.front(); //与当前要打的这个
        q.pop(); // 把对手弹出队列
        if(now_power == maxx){ //最强的这个肯定最后能获得k场胜利，那么我直接跳出来就行了
            break;
        }
        if(now_power >= next_power){ // 如果当前没有被淘汰这个能力比对手强
            ans++; //说明他获胜了一场
            q.push(next_power); //把这个输的放回队列里
        }
        else{ //如果不是，说明刚出来这个比当前这个要强
            q.push(now_power); //就把当前这个放回队列里
            now_power = next_power; //更新为当前获胜这个
            ans = 1; //获胜数要更为1！！！！！吃了好几次亏，提交次数原因都在这了
        }
    }
    cout << now_power;
    return 0;
}