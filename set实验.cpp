#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

set<int> s;

int main(){
    for (int i = 10; i >= 1; i--){
        s.insert(i);
    }
    for (auto i = s.begin(); i != s.end(); i++){
        cout << *i << endl;
    }
}