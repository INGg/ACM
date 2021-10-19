#include <iostream>
#include <cstring>

using namespace std;

// 题目要求是首尾字符只能在子串中出现一次的子串的个数
// pre表示截止i位置处，字母a(这里是代指，不是单指字母a)上一次出现的位置在哪
// num表示截至i位置处，字母a(此处同上)出现了多少次

char s[100000 + 10];
int pre[100000 + 10][26];
int num[100000 + 10][26];
int last[26 + 10];

int main(){
    cin >> s + 1;
    int l = strlen(s + 1);
    for (int i = 1; i <= l; i++){
        for (int j = 0; j < 26; j++){
            num[i][j] = num[i - 1][j]; //把上一个的数量更新过来
        }

        pre[i][s[i] - 'a'] = last[s[i] - 'a']; //上一次出现这个字母就是最新的last的位置了

        num[i][s[i] - 'a'] = num[i - 1][s[i] - 'a'] + 1; //daoi处，s[i]这个字母的个数又增加了一

        last[s[i] - 'a'] = i; // 存一下最后一次出现s[i]的位置来更新pre数组
    }

    long long ans = 0;
    for (int i = 1; i <= l; i++){
        int cnt = 0;
        for (int j = 0; j < 26; j++){
            if(s[i] - 'a' == j) //其实是可以不加的，但是我感觉加上去更好理解；不加的原因可以结合两个数组的定义得出
                continue; /*
                        解释一下为什么可以不加：因为如果枚举到尾字母，那么从i-1往前出现过的个数，一定会等价于pre[i][s[i] - 'a']所代表的地方之前的个数，
                        即(pr[i][s[i] - 'a'], i - 1]这个区间内不会出现这个尾字母，如果出现了就不符合我们要选取的某个字母
                        是截止到i最后出现的那个了
                        所以说在这个区间内num[][j]并没有加入新的个数，所以两个答案必然相等
                          */
            if(num[i - 1][j] - num[pre[i][s[i] - 'a']][j]) //中间是否出现过这个字母
                cnt++;
        }
        ans += cnt;
    }
    cout << ans;
    return 0;
}