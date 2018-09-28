#include <bits/stdc++.h>

using namespace std;

int main(){

    while(true){

        char s[5005];
        scanf("%s", s);

        long long int dp[5005];
        dp[0] = 1;
        dp[1] = 1;

        int n = strlen(s);
        if(n==1 && s[0] == '0')
            break;
        for(int i = 2; i<=n; i++){
            int d = 10*(s[i-2]-'0')+(int)(s[i-1]-'0');
            dp[i] = dp[i-1];
            if(d >= 1 && d <=26)
                dp[i] += dp[i-2];
        }

        printf("%lld\n", dp[n]);

    }

}
