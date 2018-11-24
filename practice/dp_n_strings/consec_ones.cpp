#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int dp[n+1];
        dp[0] = 0;
        dp[1] = 2;
        dp[2] = 3;

        for(int i = 3; i<=n; i++){
            dp[i] = 0;
            dp[i] += dp[i-1]/2;
            dp[i] += dp[i-2];
        }

        cout<<dp[n]<<endl;

    }

    return 0;
}
