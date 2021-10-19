#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

string num[10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

string s;

int main(){
    cin >>s;
    long long summ = 0;
    for(int i = 0; i < s.size(); i++){
        summ += s[i] - '0';
    }
    stringstream ss;
    ss << summ;
    ss >> s;
    // cout << s << endl;
    for (int i = 0; i < s.size(); i++){
        cout << num[s[i] - '0'] << " ";
    }
    return 0;
}