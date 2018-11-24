#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int w;
        cin>>w;

        int val[n];
        int we[n];

        for(int i = 0; i<n; i++)
            cin>>val[i];

        for(int i = 0; i<n; i++)
            cin>>we[i];

        int dp[n+1][w+1];

        for(int i = 0; i<=n; i++)
            for(int j = 0; j<=w; j++)
                dp[i][j] = INT_MIN;

        for(int j = 0; j<=w; j++)
            dp[0][j] = 0;

        for(int i = 0; i<=n; i++)
            dp[i][0] = 0;

        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=w; j++){

                if(j>= we[i-1])
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-we[i-1]] + val[i-1]);
                else
                    dp[i][j] = dp[i-1][j];

            }

        cout<<dp[n][w]<<endl;
    }

    return 0;
}
