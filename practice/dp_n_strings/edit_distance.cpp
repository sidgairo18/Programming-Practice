#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        string s1, s2;


        int n = s1.size();
        int m = s2.size();

        cin>>n>>m;
        cin>>s1>>s2;

        int dp[n+1][m+1];

        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=m; j++)
                dp[i][j] = INT_MAX;

        for(int i = 0; i<=m; i++)
            dp[0][i] = i;

        for(int i = 0; i<=n; i++)
            dp[i][0] = i;

        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=m; j++)
                if(s1[i-1] != s2[j-1])
                    dp[i][j] = 1+ min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                else
                    dp[i][j] = dp[i-1][j-1];

        cout<<dp[n][m]<<endl;

    }

    return 0;
}
