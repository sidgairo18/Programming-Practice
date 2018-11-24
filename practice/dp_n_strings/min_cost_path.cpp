#include <bits/stdc++.h>

using namespace std;

int main(){ 

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int a[n][n];
        int dp[n][n];

        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++){
                cin>>a[i][j];
                dp[i][j] = INT_MAX;
            }
        
        dp[0][0] = a[0][0];

        for(int i = 1; i<n; i++)
            dp[0][i] = dp[0][i-1]+a[0][i];

        for(int i = 1; i<n; i++)
            dp[i][0] = dp[i-1][0] + a[i][0];

        for(int i=1; i<n; i++)
            for(int j = 1; j<n; j++){
                dp[i][j] = min(dp[i-1][j]+a[i][j], dp[i][j-1]+a[i][j]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+a[i][j]);
            }
        cout<<dp[n-1][n-1]<<endl;




    }

    return 0;
}
