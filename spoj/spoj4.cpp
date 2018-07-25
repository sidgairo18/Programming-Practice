#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, t;

    scanf("%d", &t);

    while(t--){

        scanf("%d", &n);

        int fives = 0;
        int start = 5;

        while(start<=n){
            fives += floor(n/start);
            start *= 5;
        }

        int twos = floor(n/2);

        int ans = min(twos, fives);
        printf("%d\n", ans);
    }

    return 0;
}
