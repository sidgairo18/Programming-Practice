#include <bits/stdc++.h>

using namespace std;

int func_rev(int n){

    int rev = 0;

    while(n!=0){

        int d = n%10;
        rev = rev*10+d;
        n/=10;
    }

    return rev;
}

int main(){
    
    int t;
    int x,y;
    scanf("%d", &t);

    while(t--){
        scanf("%d%d", &x, &y);
        int ans = func_rev(x) + func_rev(y);
        printf("%d\n", func_rev(ans));
    }


    return 0;
}
