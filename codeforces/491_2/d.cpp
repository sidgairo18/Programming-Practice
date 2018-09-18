#include <bits/stdc++.h>

using namespace std;

int main(){

    string top, bot;
    cin>>top;
    cin>>bot;

    int dp[105][4];

    for(int i = 0; i<105; i++)
        dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = 0;


    int n = top.size();
    for(int i = 0; i<n; i++){
        top[i] = top[i] == 'X'? '1':'0';
        bot[i] = bot[i] == 'X'? '1':'0';
    }
    top = "00"+top;
    bot = "00"+bot;
    n = top.size();

    for(int i = 2; i<n-1; i++){

        if(top[i] - '0' + top[i+1] -'0' + bot[i] - '0' + bot[i+1] - '0'>= 2 )
        {
            int ans = INT_MIN;
            if(i > 0){
                for(int j = 0; j<4; j++)
                    ans = max(dp[i-1][j], ans); 
                for(int j = 0; j<4; j++)
                    dp[i][j] = ans;
            }
        }
        else if(top[i] - '0' + top[i+1] -'0' + bot[i] - '0' + bot[i+1] - '0' ==  1){

            int ans = INT_MIN;
            for(int j = 0; j<4; j++)
                ans = max(dp[i-2][j], ans);
            if(top[i] == '1' )
                dp[i][1] = 1+ans;

            else if(bot[i] == '1' )
                dp[i][2] = 1+ans;

            else if(top[i+1] == '1')
                dp[i][0] = 1+ans;
            else
                dp[i][3] = 1+ans;
        }
        else if(top[i] - '0' + top[i+1] -'0' + bot[i] - '0' + bot[i+1] - '0' ==  0){

            int ans = INT_MIN;
            if(i >= 2){
                for(int j = 0; j<4; j++)
                    ans = max(dp[i-2][j], ans);
                dp[i][0] = ans+1;
                dp[i][3] = ans+1;
                dp[i][1] = ans+1;
                dp[i][2] = ans+1;
            }
            ans = INT_MIN;
            dp[i][2] = max(1+dp[i-1][0], dp[i][2]);
            dp[i][1] = max(1+dp[i-1][3], dp[i][1]);
        }
    }

    int ans = INT_MIN;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<4; j++)
            ans = max(ans, dp[i][j]);

    cout<<ans<<endl;
    return 0;

}
