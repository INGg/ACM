#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[20];
char fu;
int n;
int a, b;

int main(){
	// freopen("D.out","w",stdout);
    scanf("%d\n", &n);
    
    while(n--){
        fgets(s, sizeof(s), stdin);
        if(s[0] == 'a' || s[0] == 'b' || s[0] == 'c'){
            fu = s[0];
            s[0] = ' ';
        }
        sscanf(s, "%d %d", &a, &b);
        char ans[20];
        if(fu == 'a'){
            sprintf(ans, "%d+%d=%d", a, b, a + b);
        }
        if(fu == 'b'){
            sprintf(ans, "%d-%d=%d", a, b, a - b);
        }
        if(fu == 'c'){
            sprintf(ans, "%d*%d=%d", a, b, a * b);
        }
        printf("%s\n%d\n", ans, strlen(ans));
    }
    return 0;
}