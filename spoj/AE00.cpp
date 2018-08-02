#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll dp[10005];

int main(){

    for(int i = 0; i<=10000; i++)
        dp[i] = 0;

    dp[1] = 1;
    int n;
    scanf("%d", &n);

    for(int i = 2; i<=n; i++){

        for(int j = 1; j*j<=i; j++)
            if(i%j == 0)
                dp[i] += 1;
        dp[i] += dp[i-1];
    }
    

    printf("%lld\n", dp[n]);

    return 0;
}
