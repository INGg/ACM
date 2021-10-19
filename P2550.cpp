#include <iostream>

using namespace std;

int jiang[35];
int lei[10];

int main(){
    int n;
    cin >> n;

    int a;
    for (int i = 1; i <= 7; i++){
        cin >> a;
        jiang[a] = 1;
    }

    for (int i = 1; i <= n; i++){
        int b[35] = {0};
        int ans = 0;
        for (int j = 1; j <= 7; j++){
            cin >> b[j];
            if(jiang[b[j]])
                ans++;
        }
        lei[ans]++;
    }
    cout << lei[7] << " ";
    for (int i = 6; i >= 1; i--){
        cout << lei[i] << " ";
    }
        return 0;
}