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
#define ull unsigned long long
#define re return
#define Endl "\n"
#define endl "\n"

using namespace std;

const int ull base = 12306; // 一般选一个1w左右的数，这个随便

ull h[N]; // 存哈希值，h[i]表示字符串第i个的前缀的值
ull bit[N]; //

void init_hax(){
	bit[0] = 1;
	for(int i = 1; i <= l; i++){
		bit[i] = bit[i - 1] * base; // 存base的i次方
	}
	
	for(int i = 1; i <= l; i++){
		h[i] = h[i - 1] * base + s[i];
	}
	
	/*
	我们为什么要存每一位的哈希值呢？
	它是可以用来求每一个子串的哈希值的
	如果我们求 abcdefgh 中def的子串的哈希值
	那么显然，现在abcdef = h[6], h[3] = abc;
	如果我们直接相减的话相当于竖式减法，减abc的地方是def，那肯定是不对的
	所以我们应该把它进位那么就是h[3] * bit[6 - 3]，即减去bit[len(s)]
	*/
}

void get(int l, int r){
	return h[r] - h[l - 1] * bit[r - l + 1];
}