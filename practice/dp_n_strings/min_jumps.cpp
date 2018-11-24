#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        long long int a[n];
        long long int dp[n];

        for(int i = 0; i<n; i++){

            cin>>a[i];
            dp[i] = INT_MAX;

        }

        dp[0] = 0;

        for(int i = 0; i<n; i++)
            cout<<dp[i]<<" ";
        cout<<endl;

        for(int i = 1; i<n; i++){

            for(int j = 0; j<i; j++){

                if(a[j] >= (i-j))
                    dp[i] = min(dp[i], 1+dp[j]);

            } 

        }
        for(int i = 0; i<n; i++)
            cout<<dp[i]<<" ";
        cout<<endl;

        cout<<dp[n-1]<<endl;

    }

    return 0;
}
