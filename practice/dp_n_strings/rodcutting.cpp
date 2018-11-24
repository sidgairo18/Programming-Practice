#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int a[n+1];

        for(int i = 1; i<=n; i++)
            cin>>a[i];

        int dp[n+1];
        a[0] = 0;
        dp[0] = 0;
        dp[1] = a[1];

        for(int i = 2; i<=n; i++){

            dp[i] = a[i];

            for(int j = 1; j<i; j++)
                dp[i] = max(dp[i], a[j] + dp[i-j]);


        }

        cout<<dp[n]<<endl;

    }

    return 0;
}
