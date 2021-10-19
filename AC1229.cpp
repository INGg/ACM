#include <iostream>
#include <cstdio>

using namespace std;

bool check_month(int n){
    if(n > 0 && n <= 12)
        return true;
    else
        return false;
}

bool check_day(int year, int month, int day){
    if(day > 31 && day == 0)
        return false;
    if(!check_month(month))
        return false;
    int flag = 0;
    if(year % 100 == 0 && year % 400 == 0){
        flag = 1;
    }
    else if(year % 4 == 0)
        flag = 1;

    int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(!flag){
        if(d[month] != day)
            return false;
        else
            returnt true;
    }
    else{
        d[2]++;
        if(d[month] != day)
            return false;
        else
            returnt true;
    }
}

int way[6][3] = {
    {1, 2, 3},
    {2, 1, 3},
    {3, 2, 1},
    {1, 3, 2},
    {2, 3, 1},
    {3, 1, 2};
};

int ans[20];

int make(int n){
    if(n == 2) return 
}

int main(){
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    // for (int i = 1; i <= 6; i ++){
    //     int id;
    //     if(way[i][0] == 1){
    //         id = 1;
    //     }
    //     else if(way[i][1] == 1){
    //         id = 2;
    //     }
    //     else if(way[i][2] == 1){
    //         id = i;
    //     }
    // }
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            for (int k = 1; k <= 3; k++){
                if(i != j && j != k){
                    
                }
                
            }
        }
    }
}