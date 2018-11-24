#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n,x,y,z;
        cin>>n;
        cin>>x>>y>>z;

        long long int dp[n+1];
        dp[0] = 0;

        for(int i = 1; i<=n; i++)
            dp[i] = -1;

        for(int i = 1; i<=n; i++){
            
            if(i>=x && dp[i-x] > -1)
                dp[i] = max(dp[i], 1+dp[i-x]);
            if(i>=y && dp[i-y] > -1)
                dp[i] = max(dp[i], 1+dp[i-y]);
            if(i>=z && dp[i-z] > -1)
                dp[i] = max(dp[i], 1+dp[i-z]);


        }

        cout<<dp[n]<<endl;

    }

    return 0;
}
