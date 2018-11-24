#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int price[n+1];
        for(int i = 1; i<=n; i++)
            cin>>price[i];

        int dp[n+1];
        dp[0] = 0;

        for(int i = 1; i<=n; i++)
            dp[i] = price[i];

        for(int i = 1; i<=n; i++){

            for(int j = 1; j<i; j++)
                dp[i] = max(dp[i], price[j] + dp[i-j]);

        }

        cout<<dp[n]<<endl;

    }

    return 0;
}
